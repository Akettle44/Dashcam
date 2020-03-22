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
 
void* addFrame();

int main()
{		
	bool state =  false; //control flow begins in NOT recording state
	FILE *button = NULL;
	FILE *led = NULL;
	int x = -1;
	int fcount = 0;
	char butval[] = "0";
	Mat frame;
	VideoCapture cap;
	VideoWriter video;
	init_GPIOs(button, led); //initializes gpio streams and then closes them

	pthread_t frames; //declares thread
	
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
			pthread_create(&frames, NULL, addFrame, void *(&cap), void *(&video)); //spawns thread
			state = true;
			fwrite("1", 1, sizeof("1"), led);
			usleep(2000); //prevents the on sequence from hanging onto the off sequence			
		}
		else if((strcmp(butval, "1") == 10) && (state == true)) 
		{ 
			//close video
			pthread_join(check, NULL);
			pthread_exit(NULL);
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

void* addFrame(void *)
{
	cap.set(CAP_PROP_FPS, cap.get(5)); //frame rate keeps hanging after a few seconds, forcing it to 24
	cout.flush();
	cout << "Adding frame ";
	cap >> frame;
	video << frame;	
	fcount++;	
	cout << fcount << "\n";
}

