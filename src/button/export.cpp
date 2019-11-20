#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{	
	char gpio49[] = "49";
	char gpio20[] = "20";
	
	FILE *exportled = NULL; //Linux extracts gpios as files
	FILE *exportbut = NULL; //Linux extracts gpios as files

	exportled = fopen("/sys/class/gpio/export", "w");	
	fwrite(gpio49, 1, sizeof(gpio49), exportled); //writes 1 byte (size of char) to the file
	exportbut = fopen("/sys/class/gpio/export", "w");	
	fwrite(gpio20, 1, sizeof(gpio20), exportbut); //writes 1 byte (size of char) to the file

	fclose(exportled); //closing file streams
	fclose(exportbut);

	return 0;
}
