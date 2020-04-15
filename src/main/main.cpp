/*
 * Written by Andrew Kettle, last update February 17th
*/

using namespace std;

#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <thread>
#include "../video/VideoCapture.hpp"
 
void addFrame(VideoCapture cap, VideoWriter video);

int main()
{		
	VideoCapture cap;
	VideoWriter video;

	thread frames;
	
	//begin recording video
	cap = initCapture();
	video = initWriter(cap);
	frames = thread(addFrame, cap, video);
	frames.join(); 
	closeVideo(cap, video);

	return 0;
}

void addFrame(VideoCapture cap, VideoWriter video)
{
	int fcount = 0;
	while(1)
	{
		Mat frame;
		cap.set(CAP_PROP_FPS, cap.get(5)); //frame rate keeps hanging after a few seconds, forcing it to 24
		cout << "Adding frame ";
		cap >> frame;
		video << frame;
		fcount++;
		cout << fcount << "\n";
		imshow("Video Stream", frame);

		if(waitKey(10) == 27)
		{
			break;
		}
	}
}

