/*
 * Written by Andrew Kettle, last update February 17th
*/

using namespace std;

#include <unistd.h>
#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <fstream>
#include <stdio.h>
#include "../button/button.hpp"
#include "../video/VideoCapture.hpp"
 
int checkState(bool currstate, FILE *button, FILE *led);

int main()
{		
	bool state =  false; //control flow begins in NOT recording state
	FILE *button = NULL;
	FILE *led = NULL;
	int x = -1;
	Mat frame;
	VideoCapture cap;
	VideoWriter video;
	init_GPIOs(button, led); //initializes gpio streams and then closes them

/*	pthread_t check;
	pthread_create(&check, NULL, checkState, NULL);
*/
	
	while(1) //polling
	{
		x = checkState(state, button, led);
		cout << "This is x: " << "\n";
		if(x != -1) //state needs to be changed
		{
			led = fopen("/sys/class/gpio/gpio49/value", "w");
			if(x == 1) 
			{
				//begin recording video
				cap = initCapture();
				video = initWriter(cap);
				state = true;
				fwrite("1", 1, sizeof("1"), led);
				usleep(2000); //prevents the on sequence from hanging onto the off sequence			
			}
			else if(x == 2) 
			{
				//close video
//				pthread_join(check, NULL);
//				pthread_exit(NULL);
				state = false;
				closeVideo(cap, video);
				fwrite("0", 1, sizeof("0"), led);
				cout << "Got to break \n";
				break; //breaks from infinite while
			}
			else
			{
				cout << "An error occured" << "\n";
			}
			
		}	
		else
		{
			if(state == true)
			{
				cap.set(CAP_PROP_FPS, cap.get(5)); //frame rate keeps hanging after a few seconds, forcing it to 24
				cout.flush();
				cout << "Adding frame \n";
				cap >> frame;
				video << frame;	
			}
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

int checkState(bool currstate, FILE *button, FILE *led) //returns 1 if the camera needs to be turned off, 2 if it needs to be turned on, -1 otherwise
{
		int rval = 0;
		char butval[] = "0";
		button = fopen("/sys/class/gpio/gpio20/value", "r");
		fread(butval, 1, sizeof(butval), button);
		led = fopen("/sys/class/gpio/gpio49/value", "w");

		if((strcmp(butval, "1") == 10) && (currstate == false)) 
		{
			rval = 1;
		}
		else if((strcmp(butval, "1") == 10) && (currstate == true)) 
		{
			rval = 2;
		}

		if(button != NULL)
		{
			fclose(button);
		}
		if(led != NULL)
		{
			fclose(led);
		}

		return rval;
}
