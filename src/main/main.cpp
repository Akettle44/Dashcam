/*
 * Written by Andrew Kettle, last update December 14th
*/

using namespace std;

#include "button.hpp"
#include "VideoCapture.hpp"
#include <thread>
 
int main()
{		
	VideoCapture (*fnptr)(){ Video }; //check spelling, function pointer to open_Video
	char butval[] = "0";
	bool state =  false; //control flow begins in NOT recording state
	FILE *button = NULL;
	FILE *led = NULL;
	init_GPIOs(button, led); //initializes gpio streams and then closes them, watch out for the closure
	
	while(1) //polling with a seperate thread for inputting and writing video
	{
		button = fopen("/sys/class/gpio/gpio20/value", "r");
		fread(butval, 1, sizeof(butval), button);
		led = fopen("/sys/class/gpio/gpio49/value", "w");

		if((strcmp(butval, "1") == 10) && (state == false)) 
		{
			//start new thread for recording and writing video
			thread vid(fnptr); //starts new thread of video recording
			state = true;
			fwrite("1", 1, sizeof("1"), led);			
		}
		else if((strcmp(butval, "1") == 10) && (state == true)) 
		{
			//interrupt thread 
			//stop recording video
			state = false;
			fwrite("0", 1, sizeof("0"), led);
			break; //breaks from infinite while			
		}

		if(button != NULL)
		{
			fclose(buton);
		}
		if(led != NULL)
		{
			fclose(led);
		}
	}

	if(button != NULL)
	{
		fclose(buton);
	}
	if(led != NULL)
	{
		fclose(led);
	}

	remove_GPIOs(button, led);
	return 0;
}
