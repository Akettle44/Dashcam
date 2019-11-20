#include <unistd.h>
#include <stdio.h>
#include <bool.h>
#include <linux/gpio.h>

int main() 
{
	bool state = false; //false = video is not recording, true == video is recording

	//open gpios via register values

	//set direction of gpios
	
	while(1)
	{
		if(/*button signal goes high*/ && /* state is 1*/)
		{
			//stop recording video, prepare system for shutdown
			//for now, turn OFF LED
		}

		else if(/*button signal goes high*/ && /* state is 0*/)
		{
			//begin recording video
			//for now, turn ON LED
		}
	
	}
	return 0;
}
