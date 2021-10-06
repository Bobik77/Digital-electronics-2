/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed. Use 
 * functions from GPIO library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define LED_EXTERNAL   PC5     // AVR pin where blue ext. LED is connected
//#define BUTTON_PIN  PD2    //pin of pButton connect
#define PUSH_BTN    PD0     // external pushbutton


#define BLINK_DELAY 500
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h>
#include "gpio.h"           // GPIO library for AVR-GCC

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed. Functions 
 *           from user-defined GPIO library is used.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Green LED at port B
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write_low(&PORTB, LED_GREEN);

    // Configure the second LED at port C
    GPIO_config_output(&DDRC, LED_EXTERNAL);
    GPIO_write_low(&PORTC, LED_EXTERNAL);

    // Configure Push button at port D and enable internal pull-up resistor
    GPIO_config_input_pullup(&PORTD, PUSH_BTN);

    // Infinite loop
    while (1)
    {
        if (!GPIO_read(&PORTD, PUSH_BTN)) //if pressed
        {
            GPIO_toggle(&PORTB, LED_GREEN);
            GPIO_toggle(&PORTB, LED_EXTERNAL); //toggle led state

            // Pause several milliseconds
            _delay_ms(BLINK_DELAY);
        }
    }

    // Will never reach this
    return 0;
}