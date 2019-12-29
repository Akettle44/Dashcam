#ifndef CAPTURE_H
#define CAPTURE_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <string>

using namespace cv;

#define DEBUG

VideoCapture initCapture();
VideoWriter initWriter(VideoCapture cap);
void closeVideo(VideoCapture cap, VideoWriter video);

#endif 
