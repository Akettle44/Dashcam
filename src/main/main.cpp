/*
 * Written by Andrew Kettle, last update February 17th
*/

using namespace std;

#include <unistd.h>
#include <chrono>
#include <future>
#include <iostream>
#include <semaphore.h>
#include <fstream>
#include <stdio.h>
#include <thread>
#include "../button/button.hpp"
#include "../video/VideoCapture.hpp"
 
void addFrame(VideoCapture cap, VideoWriter video, future<void> futureObj);

int main()
{		
	bool state =  false; //control flow begins in NOT recording state
	FILE *button = NULL;
	FILE *led = NULL;
	char butval[] = "0";
	VideoCapture cap;
	VideoWriter video;
	promise<void> exitSig;
	future<void> futureObj;

	futureObj = exitSig.get_future();
	init_GPIOs(button, led); //initializes gpio streams and then closes them
	thread frames;
	
	while(1) //polling
	{
		button = fopen("/sys/class/gpio/gpio20/value", "r");
		fread(butval, 1, sizeof(butval), button);
		led = fopen("/sys/class/gpio/gpio49/value", "w"); 

		if((strcmp(butval, "1") == 10) && (state == false)) 
		{
			//begin recording video
			cap = initCapture();
			video = initWriter(cap);
			frames = thread(addFrame, cap, video, move(futureObj));
			state = true;
			fwrite("1", 1, sizeof("1"), led);
			usleep(2000); //prevents the on sequence from hanging onto the off sequence			
		}
		else if((strcmp(butval, "1") == 10) && (state == true)) 
		{ 
			//close video
			exitSig.set_value(); //tells thread to exit	
			frames.join(); //joins threads together
			state = false;
			closeVideo(cap, video);
			fwrite("0", 1, sizeof("0"), led);
			cout << "Got to break \n";
			break; //breaks from infinite while
		}
	}

	cout << "Everything yeeted \n";
	if(button != NULL)
	{
		fclose(button);
	}
	if(led != NULL)
	{
		fclose(led);
	}

	remove_GPIOs(button, led);
	return 0;
}

void addFrame(VideoCapture cap, VideoWriter video, future<void> futureObj)
{
	while(futureObj.wait_for(chrono::milliseconds(1)) == future_status::timeout)
	{
		Mat frame;
		cap.set(CAP_PROP_FPS, cap.get(5)); //frame rate keeps hanging after a few seconds, forcing it to 24
		cout << "Adding frame " << "\n";
		cap >> frame;
		video << frame;	
	}
}

