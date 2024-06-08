#include "MyImage.h"


MyImage::MyImage(const cv::String& path) {
	this->img = cv::imread(path);
	this->originalImg = cv::imread(path);
};

cv::Mat MyImage::getCVMat() {
	return this->img;
}

void MyImage::scaleUp() {
	resize(1.2, 1.2, cv::Size());
}

void MyImage::scaleDown() {
	MyImage::resize(0.8, 0.8, cv::Size());
}

void MyImage::resize(double fx = 0, double fy = 0, cv::Size dsize = cv::Size())
{
	cv::resize(this->img, this->img, dsize, fx, fy);
}

void MyImage::turngGray()
{
	cv::cvtColor(this->img, this->img, cv::ColorConversionCodes::COLOR_BGR2GRAY);

}

void MyImage::blur(int kernelSize)
{
	cv::blur(this->img, this->img, cv::Size(kernelSize, kernelSize));

}

void MyImage::detectEdges(int kernelSize, int upperThreshold, int lowerThreshold)
{
	MyImage::turngGray();
	MyImage::blur(kernelSize);
	cv::Canny(this->img, this->img, lowerThreshold, upperThreshold);

}

void MyImage::brightnessAndContrastControl(double alpha, double beta)
{
	this->img.convertTo(this->img, CV_8U, alpha, beta);
}

void MyImage::rgbControl(double r, double g, double b) {
	double maxValue = 255;
	double minValue = 0;
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			double blue = img.at<cv::Vec3b>(y, x)[0] + b;
			if (blue >= maxValue) {
				img.at<cv::Vec3b>(y, x)[0] = maxValue;
			}
			else if (blue <= minValue) {
				img.at<cv::Vec3b>(y, x)[0] = minValue;
			}
			else {
				img.at<cv::Vec3b>(y, x)[0] = blue;
			}
			double green = img.at<cv::Vec3b>(y, x)[1] + g;
			if (green >= maxValue) {
				img.at<cv::Vec3b>(y, x)[1] = maxValue;
			}
			else if (green <= minValue) {
				img.at<cv::Vec3b>(y, x)[1] = minValue;
			}
			else {
				img.at<cv::Vec3b>(y, x)[1] = green;
			}
			double red = img.at<cv::Vec3b>(y, x)[2] + r;
			if (red >= maxValue) {
				img.at<cv::Vec3b>(y, x)[2] = maxValue;
			}
			else if (red <= minValue) {
				img.at<cv::Vec3b>(y, x)[2] = minValue;
			}
			else {
				img.at<cv::Vec3b>(y, x)[2] = red;
			}
		}
	}
}

void MyImage::save(std::string path)
{
	cv::imwrite(path, this->img);
}

void MyImage::undoAll()
{
	cv::Size size = this->img.size();
	this->img = this->originalImg;
	MyImage::resize(0, 0, size);
	
}

System::Drawing::Size MyImage::getSize()
{
	return System::Drawing::Size(this->img.cols, this->img.rows);
}


void MyImage::erosion(int changingType, int kernelsize) {
	int type = 0;
	if (changingType == 0) {
		type = cv::MORPH_RECT;
	}
	else if (changingType == 1) {
		type = cv::MORPH_CROSS;
	}
	else if (changingType == 2) {
		type = cv::MORPH_ELLIPSE;
	}
	cv::Mat element = getStructuringElement(type,
		cv::Size(2 * kernelsize + 1, 2 * kernelsize + 1),
		cv::Point(kernelsize, kernelsize));
	cv::erode(this->img, this->img, element);

}

void MyImage::dilation(int changingType, int kernelsize) {
	int type = 0;
	if (changingType == 0) {
		type = cv::MORPH_RECT;
	}
	else if (changingType == 1) {
		type = cv::MORPH_CROSS;
	}
	else if (changingType == 2) {
		type = cv::MORPH_ELLIPSE;
	}
	cv::Mat element = getStructuringElement(type,
		cv::Size(2 * kernelsize + 1, 2 * kernelsize + 1),
		cv::Point(kernelsize, kernelsize));
	cv::dilate(this->img, this->img, element);
}



