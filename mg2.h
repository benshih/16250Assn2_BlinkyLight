#ifndef __MINIGADGET2_H__
#define __MINIGADGET2_H__

#include <avr/io.h>
#include <util/delay.h>


void initLED(void);
void setLED(int,int,int);
void initButton(void);
int	 buttonPressed(void);

void initSystem(void);


#endif