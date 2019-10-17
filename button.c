#include <unistd.h>
#include <stdio.h>
#include <linux/gpio.h>

int main()
{
	FILE *io, *iodir, *ioval; //initialization for io, direction and value from direction
	
	io = fopen("/sys/class/gpio/export","w"); //open gpio for writing
	fseek(io, 0, SEEK_SET); //update file pointer to offset, Seek_Set allows this
	fprintf(io,"%d",20); //prints contents of file
    fflush(io); //cleans out output buffer

	iodir = fopen("/sys/class/gpio/gpio20/direction","w"); //open direction for writing
	fseek(iodir, 0, SEEK_SET);
	fprintf(iodir, "out"); //sets input direction as in
	fflush(iodir);

	ioval = fopen("/sys/class/gpio/gpio20/value","w");
   	fseek(ioval,0,SEEK_SET);

	while(1) 
	{
		fprintf(ioval,"%d",1);
        fflush(ioval);
        sleep(1);
        fprintf(ioval,"%d",0);
        fflush(ioval);
        sleep(1);
	}

fclose(io);
fclose(iodir);
fclose(ioval);
return 0;

}
