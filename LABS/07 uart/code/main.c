/***********************************************************************
 * 
 * Analog-to-digital conversion with displaying result on LCD and 
 * transmitting via UART.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/


#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Pjeter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function
#include "uart.h"           // Peter Fleury's UART library


/* Constants ----------------------------------------------------------*/
//array of strings key names
const char *key_name_str[6] = { "NONE", "SELECT", "LEFT", "DOWN","UP","RIGHT"};


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion four times 
 *           per second. Send value to LCD and UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);
    lcd_gotoxy(1, 0); lcd_puts("value:");
    lcd_gotoxy(3, 1); lcd_puts("key:");
    lcd_gotoxy(8, 0); lcd_puts("a");    // Put ADC value in decimal
    lcd_gotoxy(13,0); lcd_puts("b");    // Put ADC value in hexadecimal
    lcd_gotoxy(8, 1); lcd_puts("c");    // Put button name here

    // Configure ADC to convert PC0[A0] analog value
    // Set ADC reference to AVcc
    ADMUX &= ~(1<<REFS1);
    ADMUX |= (1<<REFS0);
    // Set input channel to ADC0 (ADMUX = xxxx_0000)
    ADMUX &= ~((1<<MUX3)|(1<<MUX2)|(1<<MUX1)|(1<<MUX0));
    // Enable ADC module
    ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 262 ms and enable overflow interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();
    // Initialize UART to asynchronous, 8N1, 9600
    uart_init(UART_BAUD_SELECT(9600, 16000000UL));
    
    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion four times
 *           per second.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    ADCSRA |= (1<<ADSC);
    
}

/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    //clear first line
    lcd_gotoxy(8,0); //set cursor
    lcd_puts("        "); 

    // read adc value
    uint16_t ADC_val = ADC;
    
    char lcd_string[4] = "    ";      // String for converting numbers by itoa()
    //show in DEC
    itoa(ADC_val, lcd_string, 10);     // Convert to str
    lcd_gotoxy(8,0); //set cursor to A
    lcd_puts(lcd_string); 
    // show in HEX
    itoa(ADC_val, lcd_string, 16);     // Convert to str
    lcd_gotoxy(13,0); //set cursor to B
    lcd_puts(lcd_string);
    
    // Show addicted key-label
    uint8_t key = 0;
    if (ADC_val > 1020) key = 0; //NON
    else if (ADC_val > 600) key = 1; //SEL
    else if (ADC_val > 390) key = 2; //LEFT
    else if (ADC_val > 200) key = 3; //DWN
    else if (ADC_val > 50)  key = 4; //UP
    else key = 5; //RIGHT
    lcd_gotoxy(8,1); //set cursor to C
    lcd_puts("        "); //clear 2nd line disp
    lcd_gotoxy(8,1); //set cursor to C
    lcd_puts(key_name_str[key]); //show on LCD
    uart_puts(key_name_str[key]);//send via COM
    uart_puts("\n"); //line feed
}