/*
 * Written by Andrew Kettle, last update February 17th
*/

using namespace std;

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "../button/button.hpp"
#include "../video/VideoCapture.hpp"
 
int main()
{		
	char butval[] = "0";
	bool state =  false; //control flow begins in NOT recording state
	FILE *button = NULL;
	FILE *led = NULL;
	Mat frame;
	VideoCapture cap;
	VideoWriter video;
	init_GPIOs(button, led); //initializes gpio streams and then closes them, watch out for the closure
	

	while(1) //polling
	{
		if(state == true)
		{
			cap.set(CAP_PROP_FPS, 24); //frame rate keeps hanging after a few seconds, forcing it to 24
			cout.flush();
			cout << "Adding frame \n";
			cap >> frame;
			video << frame;	
		}
		
		button = fopen("/sys/class/gpio/gpio20/value", "r");
		fread(butval, 1, sizeof(butval), button);
		led = fopen("/sys/class/gpio/gpio49/value", "w");

		if((strcmp(butval, "1") == 10) && (state == false)) 
		{
			//begin recording video
			cap = initCapture();
			video = initWriter(cap);
			state = true;
			fwrite("1", 1, sizeof("1"), led);
			usleep(2000); //prevents the on sequence from hanging onto the off sequence			
		}
		else if((strcmp(butval, "1") == 10) && (state == true)) 
		{
			//close video
			state = false;
			closeVideo(cap, video);
			fwrite("0", 1, sizeof("0"), led);
			cout << "Got to break \n";
			break; //breaks from infinite while			
		}


		if(button != NULL)
		{
			fclose(button);
		}
		if(led != NULL)
		{
			fclose(led);
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
