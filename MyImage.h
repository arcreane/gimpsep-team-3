#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream> 
#include <stack>

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
	void brightnessAndContrastControl(double alpha, double beta);
	void rgbControl(double r, double g, double b);


	void save(std::string path);

	void undoAll();
	void undo();


	System::Drawing::Size getSize();

private:
	std::stack<cv::Mat> imgStack;
};

