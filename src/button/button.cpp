/*
 * Written by Andrew Kettle
 * functional, but could be cleaned up extensively by removing extra filestreams
*/
#include "button.hpp"

using namespace std;


char gpio49[] = "49";
char gpio20[] = "20";
char out[] = "out";
char in[] = "in";

void init_GPIOs(FILE *button, FILE *led) //maybe change security later by making private and adding parameters
{
	//extract gpios
	led = fopen("/sys/class/gpio/export", "w");	
	fwrite(gpio49, 1, sizeof(gpio49), led); //writes 1 byte (size of char) to the file
	button = fopen("/sys/class/gpio/export", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), button); //writes 1 byte (size of char) to the file
	
	fclose(led); //closing file streams
	fclose(button);

	//set direction of gpios
	led = fopen("/sys/class/gpio/gpio49/direction", "w");
	fwrite(out, 1, sizeof(out), led); 
	button = fopen("/sys/class/gpio/gpio20/direction", "w");
	fwrite(in, 1, sizeof(in), button); 

	fclose(led); //closing file streams
	fclose(button);
}

void remove_GPIOs(FILE *button, FILE *led)
{
	led = fopen("/sys/class/gpio/unexport", "w");	
	fwrite(gpio49, 1, sizeof(gpio49), led); //writes 1 byte (size of char) to the file
	button = fopen("/sys/class/gpio/unexport", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), button); //writes 1 byte (size of char) to the file

	fclose(led); //closing file streams
	fclose(button);
}

