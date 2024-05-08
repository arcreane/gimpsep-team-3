#include "MyImage.h"


MyImage::MyImage(const cv::String& path) {
	this->img = cv::imread(path);
};

cv::Mat MyImage::getCVMat() {
	return this->img;
}

void MyImage::scaleUp() {
	cv::resize(this->img, this->img, cv::Size(), 1.2, 1.2);
}

void MyImage::scaleDown() {
	cv::resize(this->img, this->img, cv::Size(), 0.8, 0.8);
}

System::Drawing::Size MyImage::getSize()
{
	return System::Drawing::Size(this->img.cols, this->img.rows);
}