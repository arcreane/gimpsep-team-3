#include "MyImage.h"


MyImage::MyImage(const cv::String& path) {
	cv::Mat img = cv::imread(path);
	this->imgStack.push(img);
};

cv::Mat MyImage::getCVMat() {
	return this->imgStack.top();
}

void MyImage::scaleUp() {
	resize(1.2, 1.2, cv::Size());
}

void MyImage::scaleDown() {
	MyImage::resize(0.8, 0.8, cv::Size());
}

void MyImage::resize(double fx = 0, double fy = 0, cv::Size dsize = cv::Size())
{
	cv::Mat newImg = this->imgStack.top().clone();
	cv::resize(newImg, newImg, dsize, fx, fy);
	this->imgStack.push(newImg);
}

void MyImage::turngGray()
{
	cv::Mat newImg = this->imgStack.top().clone();
	cv::cvtColor(newImg, newImg, cv::ColorConversionCodes::COLOR_BGR2GRAY);
	this->imgStack.push(newImg);

}

void MyImage::blur(int kernelSize)
{
	cv::Mat newImg = this->imgStack.top().clone();
	cv::blur(newImg, newImg, cv::Size(kernelSize, kernelSize));
	this->imgStack.push(newImg);

}

void MyImage::detectEdges(int kernelSize, int upperThreshold, int lowerThreshold)
{
	MyImage::turngGray();
	MyImage::blur(kernelSize);
	cv::Mat newImg = this->imgStack.top().clone();
	cv::Canny(newImg, newImg, lowerThreshold, upperThreshold);
	this->imgStack.push(newImg);

}

void MyImage::brightnessAndContrastControl(double alpha, double beta)
{
	cv::Mat newImg = this->imgStack.top().clone();
	newImg.convertTo(newImg, CV_8U, alpha, beta);
	this->imgStack.push(newImg);
}

void MyImage::rgbControl(double r, double g, double b) {
	double maxValue = 255;
	double minValue = 0;
	cv::Mat newImg = this->imgStack.top().clone();
	for (int y = 0; y < newImg.rows; y++) {
		for (int x = 0; x < newImg.cols; x++) {
			double blue = newImg.at<cv::Vec3b>(y, x)[0] + b;
			if (blue >= maxValue) {
				newImg.at<cv::Vec3b>(y, x)[0] = maxValue;
			}
			else if (blue <= minValue) {
				newImg.at<cv::Vec3b>(y, x)[0] = minValue;
			}
			else {
				newImg.at<cv::Vec3b>(y, x)[0] = blue;
			}
			double green = newImg.at<cv::Vec3b>(y, x)[1] + g;
			if (green >= maxValue) {
				newImg.at<cv::Vec3b>(y, x)[1] = maxValue;
			}
			else if (green <= minValue) {
				newImg.at<cv::Vec3b>(y, x)[1] = minValue;
			}
			else {
				newImg.at<cv::Vec3b>(y, x)[1] = green;
			}
			double red = newImg.at<cv::Vec3b>(y, x)[2] + r;
			if (red >= maxValue) {
				newImg.at<cv::Vec3b>(y, x)[2] = maxValue;
			}
			else if (red <= minValue) {
				newImg.at<cv::Vec3b>(y, x)[2] = minValue;
			}
			else {
				newImg.at<cv::Vec3b>(y, x)[2] = red;
			}
		}
	}
	this->imgStack.push(newImg);
}

void MyImage::save(std::string path)
{
	cv::imwrite(path, this->imgStack.top());
}

void MyImage::undoAll()
{
	while (imgStack.size() > 1) {
		this->imgStack.pop();
	}
}

void MyImage::undo()
{
	this->imgStack.pop();
}

System::Drawing::Size MyImage::getSize()
{
	cv::Mat currentImg = this->imgStack.top();
	return System::Drawing::Size(currentImg.cols, currentImg.rows);
}