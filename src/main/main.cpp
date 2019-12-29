/*
 * Written by Andrew Kettle, last update December 14th
*/

using namespace std;

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
	
	while(1) //polling with a seperate thread for inputting and writing video
	{
		if(state == true)
		{
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
		}
		else if((strcmp(butval, "1") == 10) && (state == true)) 
		{
			//close video
			closeVideo(cap, video);
			state = false;
			fwrite("0", 1, sizeof("0"), led);
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
