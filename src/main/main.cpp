/*
 * Written by Andrew Kettle, last update June 27th
*/
using namespace std;

#include <unistd.h>
#include <chrono>
#include <atomic>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <thread>
#include "../button/button.hpp"
#include "../video/VideoCapture.hpp"
 
void addFrame();
bool addingFrames = false;

int main()
{		
	char butval[] = "0";
	bool state = false; //control flow begins in NOT recording state
	FILE *button = NULL;
	FILE *led = NULL;

	thread frames;
	init_GPIOs(button, led); //initializes gpio streams and then closes them

	while(1) //polling
	{
		button = fopen("/sys/class/gpio/gpio20/value", "r");
		fread(butval, 1, sizeof(butval), button);

		if((strcmp(butval, "1") == 10) && (state == false)) 
		{
			led = fopen("/sys/class/gpio/gpio49/value", "w"); 
			//begin recording video
			addingFrames = true;
			state = true;
			fwrite("1", 1, sizeof("1"), led);
			fclose(led);
			frames = thread(addFrame);
			usleep(200000); //prevents the on sequence from hanging onto the off sequence			
		}
		else if((strcmp(butval, "1") == 10) && (state == true)) 
		{ 
			led = fopen("/sys/class/gpio/gpio49/value", "w"); 
			//close video
			addingFrames = false;
			state = false;
			frames.join();
			fwrite("0", 1, sizeof("0"), led);
			fclose(led);
			cout << "Got to break \n";
			break; //breaks from infinite while
		}
		if(button != NULL) //Close the button file pointer if it needs to be closed
		{
			fclose(button);
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

void addFrame()
{
	VideoCapture cap;
	VideoWriter video;
	Mat frame;
	cap = initCapture();
	video = initWriter(cap);

	while(addingFrames)
	{
		cout << "Adding frame " << "\n";
		cap >> frame;
		video << frame;	
	}
	closeVideo(cap, video);
}
