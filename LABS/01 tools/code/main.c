/***********************************************************************
 * 
 * Blink a LED and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Last edit: 26.9.21 PAVEL VANEK
 **********************************************************************/

#define LED_GREEN   PB5 // AVR pin where green LED is connected

// morse marks durations in ms
#define dit 100         // . change speed here
#define dash 3*dit     // -
#define gap_length dit  // gap between marks
#define short_space_length 3*dit // between letters
#define long_space_length 5*dit // between words

#ifndef F_CPU           // Preprocessor directive allows for conditional
                        // compilation. The #ifndef means "if not defined".
# define F_CPU 16000000 // CPU frequency in Hz required for delay
#endif                  // The #ifndef directive must be closed by #endif

/* Includes ----------------------------------------------------------*/
/* Include another C language file into the current file at the location
 * of the #include statement prior to compiling the source code.
 */
#include <util/delay.h> // Functions for busy-wait delay loops
#include <avr/io.h>     // AVR device-specific IO definitions





/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Purpose: Delay defined time in ms
 **********************************************************************/
void my_delay_ms(int n)
{
	while(n--) {
		_delay_ms(1);
	}
}

/**********************************************************************
 * Purpose:  Send dit or dash mark
 **********************************************************************/
void send_mark(int mark_length)
{   //mark_lenght in ms

	DDRB = DDRB | (1<<LED_GREEN);	//turn on LED
	my_delay_ms(mark_length);		//mark delay
	PORTB = PORTB & ~(1<<LED_GREEN);//turn off LED
	my_delay_ms(gap_length);		//gap between marks
}

/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Sending hello message in loop in morse code via LED
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop
    while (1)
    {   //H
        send_mark(dit);
        send_mark(dit);
        send_mark(dit);
        send_mark(dit);
        _delay_ms(short_space_length);
        //E
        send_mark(dit);
        _delay_ms(short_space_length);
        //L
        send_mark(dit);
        send_mark(dash);
        send_mark(dit);
        send_mark(dit);
        _delay_ms(short_space_length);
        //L
        send_mark(dit);
        send_mark(dash);
        send_mark(dit);
        send_mark(dit);
        _delay_ms(short_space_length);
        //O
        send_mark(dash);
        send_mark(dash);
        send_mark(dash);
        _delay_ms(short_space_length);
        //W
        send_mark(dit);
        send_mark(dash);
        send_mark(dash);
        _delay_ms(long_space_length);
    }

    // Will never reach this
    return 0;
}


