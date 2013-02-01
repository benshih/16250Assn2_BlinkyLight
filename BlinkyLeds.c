#include "mg2.h"

void waitforbutton(void)
{
	while(!buttonPressed())
	{
		setLED(1,0,0);
		_delay_ms(50);
		setLED(0,0,0);
		_delay_ms(200);
	}
}

int main(void)
{
	int led = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
	int direction = 0;
	
	initSystem();

	waitforbutton();

	while(1)
	{		
		if(direction == 1) {
			led--;
		}
		else {
			led++;
		}
		
		// Preventing underflows
		if(led == 0) {
			direction = 0;
		}
		
		
		red = (led &   0b00000100)>>2;
		green = (led & 0b00000010)>>1;
		blue = (led &  0b00000001);

		if(buttonPressed()) {
			direction ^= 1;	
		}
		setLED(red, green, blue);
		_delay_ms(250);
		
	}
}