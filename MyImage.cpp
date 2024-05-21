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

void MyImage::blur()
{
	cv::blur(this->img, this->img, cv::Size(5, 5));

}

void MyImage::detectEdges()
{
	MyImage::turngGray();
	MyImage::blur();
	cv::Canny(this->img, this->img, 100, 200);

}

void MyImage::brightnessAndContrastControl(double alpha, double beta)
{
	this->img.convertTo(this->img, CV_8U, alpha, beta);
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