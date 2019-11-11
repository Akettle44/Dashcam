#include <unistd.h>
#include <stdio.h>

using namespace std;

int main()
{	
	char *ledval = "0";
	char *butval = "0";
	
	char gpio48[] = "48";
	char gpio20[] = "20";
	char out[] = "out";
	char in[] = "in";
	
	FILE *exportled = NULL; //Linux extracts gpios as files
	FILE *directionled = NULL;
	FILE *valueled = NULL;

	FILE *exportbut = NULL; //Linux extracts gpios as files
	FILE *directionbut = NULL;
	FILE *valuebut = NULL;

	bool state = false; //false = video is not recording, true = video is recording
	
	//extract gpios
	exportled = fopen("/sys/class/gpio", "w");	
	fwrite(gpio48, 1, sizeof(gpio48), exportled); //writes 1 byte (size of char) to the file
	exportbut = fopen("/sys/class/gpio", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), exportbut); //writes 1 byte (size of char) to the file

	fclose(exportled); //closing file streams
	fclose(exportbut);

	//set direction of gpios
	directionled = fopen("/sys/class/gpio/gpio48", "w");
	fwrite(out, 1, sizeof(out), directionled); 
	directionbut = fopen("/sys/class/gpio/gpio20", "w");
	fwrite(in, 1, sizeof(in), directionbut); 

	fclose(directionled); //closing file streams
	fclose(directionbut);
	
	while(1)
	{
		valuebut = fopen("sys/class/gpio/gpio20", "r");
		fread(butval, 1, sizeof(ledval), valuebut);		
	
		valueled = fopen("sys/class/gpio/gpio48", "w");

		if((butval[0] == "1") && (state == false)) //maybe change to string comp later?
		{
			//stop recording video, write video (later)
			*ledval = "0"; //turn LED off
			fwrite(ledval, 1, sizeof(ledval), valueled);			
		}

		else if((butval[0] == "0") && (state == true)) //maybe change to string comp later?
		{
			//begin recording video (later)
			*ledval = "1"; //turn LED on
			fwrite(ledval, 1, sizeof(ledval), valueled);			
		}
		fclose(valuebut);
		fclose(valueled);	
	}
	return 0;

}
