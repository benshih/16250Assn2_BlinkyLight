/*  This is the only file you need to edit, and the only functions you need to modify are:
 *  setLED
 *  initLED
 *  buttonPressed
 *  initButton
 */

 /*
Red LED is on port B, pin 1
Green LED is on port A, pin 7
Blue LED is on port A, pin 3
Button is on port B, pin 2
The button is high when not pressed, low when pressed
The LEDs are on when their signal is low, off when signal is high
 */

#include "mg2.h"


#define RED PB1
#define GREEN PA7
#define BLUE PA3
#define BUTTON PB2
#define READBUTTON ~PINB & 0x04

/*  In the if-else statements here you should set the appropriate
    LED pin to high or low based on the input.  For example, if r
	is a value other than 0, the red element of the LED should be turned
	on. */
void setLED(int r, int g, int b)
{
	if(r) // True if r != 0.
	{
		PORTB &= ~_BV(RED); // Turn on RED by setting the output to low (because we are active low).
	}
	else
	{
		PORTB |= _BV(RED); // Turn off RED.
	}
	if(g)
	{
		PORTA &= ~_BV(GREEN); // Turn on GREEN.
	}
	else
	{
		PORTA |= _BV(GREEN); // Turn off GREEN.
	}
	if(b)
	{
		PORTA &= ~_BV(BLUE); // Turn on BLUE.
	}
	else
	{
		PORTA |= _BV(BLUE); // Turn off BLUE.
	}
}

/* In this function you should set the LED pins to be outputs and
   set them high to turn them off (because our LEDs are active low)  */
void initLED()
{
	DDRB |= _BV(RED);
	DDRA |= _BV(GREEN);
	DDRA |= _BV(BLUE);

	PORTB |= _BV(RED);
	PORTA |= _BV(GREEN);
	PORTA |= _BV(BLUE);
}

/*  In this function you should set the button pin to be an input*/
void initButton()
{
	DDRB &= ~_BV(BUTTON);
}

/*  In this function, return a non-zero value if the button was pressed, and 0
    if it is not pressed. */

// The button is high when not pressed, low when pressed
int buttonPressed()
{
	if(READBUTTON)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//http://atmega32-avr.com/reading-switches-with-using-attiny-microcontrollers/

// You do not need to modify any code beyond this point

void initSystem()
{

	initLED();
	initButton();

}
