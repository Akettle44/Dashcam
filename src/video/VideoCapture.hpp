#ifndef CAPTURE_H
#define CAPTURE_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <string>

#define DEBUG

using namespace cv;

VideoCapture openVideo();
void writeVideo(VideoCapture cap);

#endif 
