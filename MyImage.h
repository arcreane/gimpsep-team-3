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
	void resize(double fx, double fy, cv::Size dsize);
	void turngGray();
	void blur(int kernelSize);
	void detectEdges(int kernelSize, int upperThreshold, int lowerThreshold);


	void save(std::string path);

	void undoAll();


	System::Drawing::Size getSize();

private:
	cv::Mat img;
	cv::Mat originalImg;
};

