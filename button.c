#include <stdio.h>

int main()
{
	FILE *io, *iodir, *ioval; //initialization for io, direction and value from direction
	
	io = fopen("/sys/class/gpio/export", w); //open gpio for writing
	fseek(io, 0, SEEK_SET); //update file pointer to the end, should this seek to 48??
	fprintf(io,"%d",48); //prints contents of file
    fflush(io); //cleans out output buffer




}
