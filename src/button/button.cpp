/*
 * Written by Andrew Kettle
 * Could be cleaned up extensively by removing extra filestreams
*/


#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{	
	char butval[] = "0";
	
	char gpio49[] = "49";
	char gpio20[] = "20";
	char out[] = "out";
	char in[] = "in";
	
	FILE *exportled = NULL; //Linux extracts gpios as files
	FILE *directionled = NULL;
	FILE *valueled = NULL;
	FILE *unexportled = NULL; //Linux extracts gpios as files

	FILE *exportbut = NULL; //Linux extracts gpios as files
	FILE *directionbut = NULL;
	FILE *valuebut = NULL;
	FILE *unexportbut = NULL; //Linux extracts gpios as files

	bool state = false; //false = video is not recording, true = video is recording
	
	//extract gpios
	exportled = fopen("/sys/class/gpio/export", "w");	
	fwrite(gpio49, 1, sizeof(gpio49), exportled); //writes 1 byte (size of char) to the file
	exportbut = fopen("/sys/class/gpio/export", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), exportbut); //writes 1 byte (size of char) to the file
	
	fclose(exportled); //closing file streams
	fclose(exportbut);

	//set direction of gpios
	directionled = fopen("/sys/class/gpio/gpio49/direction", "w");
	fwrite(out, 1, sizeof(out), directionled); 
	directionbut = fopen("/sys/class/gpio/gpio20/direction", "w");
	fwrite(in, 1, sizeof(in), directionbut); 

	fclose(directionled); //closing file streams
	fclose(directionbut);
	
	while(1)
	{
		valuebut = fopen("/sys/class/gpio/gpio20/value", "r");
		fread(butval, 1, sizeof(butval), valuebut);		
	
		valueled = fopen("/sys/class/gpio/gpio49/value", "w");

		if((strcmp(butval, "1") == 0) && (state == false)) //maybe change to string comp later?
		{
			//begin recording video
			state = true;
			fwrite("1", 1, sizeof("1"), valueled);			
		}

		else if((strcmp(butval, "0") == 0) && (state == true)) //maybe change to string comp later?
		{
			//stop recording video
			state = false;
			fwrite("0", 1, sizeof("0"), valueled);			
		}
		fclose(valuebut);
		fclose(valueled);	
	}

	unexportled = fopen("/sys/class/gpio/unexport", "w");	
	fwrite(gpio49, 1, sizeof(gpio49), unexportled); //writes 1 byte (size of char) to the file
	unexportbut = fopen("/sys/class/gpio/unexport", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), unexportbut); //writes 1 byte (size of char) to the file

	fclose(unexportled); //closing file streams
	fclose(unexportbut);

	return 0;

}
