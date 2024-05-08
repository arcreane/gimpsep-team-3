#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

class MyImage
{
public:
	MyImage(const cv::String& path);
	cv::Mat getCVMat(); 

	void scaleUp();
	void scaleDown();


	System::Drawing::Size getSize();

private:
	cv::Mat img;
};

