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