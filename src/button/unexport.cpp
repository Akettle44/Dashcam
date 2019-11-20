#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{	
	char gpio49[] = "49";
	char gpio20[] = "20";
	
	FILE *unexportled = NULL; //Linux extracts gpios as files
	FILE *unexportbut = NULL; //Linux extracts gpios as files

	unexportled = fopen("/sys/class/gpio/unexport", "w");	
	fwrite(gpio49, 1, sizeof(gpio49), unexportled); //writes 1 byte (size of char) to the file
	unexportbut = fopen("/sys/class/gpio/unexport", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), unexportbut); //writes 1 byte (size of char) to the file

	fclose(unexportled); //closing file streams
	fclose(unexportbut);

	return 0;
}
