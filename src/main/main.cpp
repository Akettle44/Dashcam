/*
 * Written by Andrew Kettle
 * functional, but could be cleaned up extensively by removing extra filestreams
*/
#include "button.hpp"
#include "VideoCapture.hpp"

int main()
{		
	char butval[] = "0";
	bool state =  false; //state of the program
	FILE *button = NULL;
	FILE *led = NULL;
	Mat frame;
	VideoCapture cap;

	init_GPIOs(button, led);
	
	while(1)
	{
		if(state == true)
		{
			//currenlty writing video
			cap >> frame;
			video << frame;

			if((strcmp(butval, "1") == 10) && (state == true)) 
			{
				//stop recording video
				state = false;
				fwrite("0", 1, sizeof("0"), led);
				break; //breaks from infinite while			
			}
		}

		else
		{
			button = fopen("/sys/class/gpio/gpio20/value", "r");
			fread(butval, 1, sizeof(butval), button);
			led = fopen("/sys/class/gpio/gpio49/value", "w");

			if((strcmp(butval, "1") == 10) && (state == false)) 
			{
				//begin recording video
				cap = openVideo();	
				state = true;
				fwrite("1", 1, sizeof("1"), led);			
			}
			else if((strcmp(butval, "1") == 10) && (state == true)) 
			{
				//stop recording video
				state = false;
				fwrite("0", 1, sizeof("0"), led);
				break; //breaks from infinite while			
			}

		fclose(button);
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
