#ifndef _BUTTON_
#define _BUTTON_

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

using namespace std;

char gpio49[] = "49";
char gpio20[] = "20";
char out[] = "out";
char in[] = "in";

//initializes GPIOS
void init_GPIOs(FILE *button, FILE *led); 
//removes GPIOs
void remove_GPIOs(FILE *button, FILE *led);

#endif
