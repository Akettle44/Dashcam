#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//initializes GPIOS
void init_GPIOs(FILE *button, FILE *led); 
//removes GPIOs
void remove_GPIOs(FILE *button, FILE *led);

#endif
