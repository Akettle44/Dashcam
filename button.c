#include <stdio.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/irq.h>

int main()
{
	FILE *io, *iodir, *ioval; //initialization for io, direction and value from direction
	
	io = fopen("/sys/class/gpio/export", w); //open gpio for writing
	fseek(io, 0, SEEK_SET); //update file pointer to offset, Seek_Set allows this
	fprintf(io,"%d",48); //prints contents of file
    fflush(io); //cleans out output buffer

	iodir = fopen("/sys/class/gpio/gpio48/direction", w); //open direction for writing
	fseek(iodir, 0, SEEK_SET);
	fprintf(iodir, "in"); //sets input direction as in
	fflsuh(iodir);

	ioval = fopen("/sys/class/gpio/gpio48/value", "w");
    fseek(ioval,0,SEEK_SET);
	


}
