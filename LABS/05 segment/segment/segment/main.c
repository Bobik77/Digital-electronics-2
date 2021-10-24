/***********************************************************************
 * 
 * Decimal counter with 7-segment output.
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
#include "segment.h"        // Seven-segment display library for AVR-GCC


/* Variables ---------------------------------------------------------*/
// Active-low digit 0 to 9
uint8_t segment_value[] = {
    // abcdefgDP
    0b00000011,     // Digit 0
    0b10011111,          // Digit 1
    0b00100101,          // Digit 2
    0b00001101,     // Digit 3
    0b10011001,          // ...
    0b01001001,
    0b01000001,
    0b00011111,
    0b00000001,
    0b00001001
};

// Active-high position 0 to 3
uint8_t segment_position[] = {
    // p3p2p1p0....
    0b00010000,     // Position 0
    0b00100000,     // Position 1
    0b01000000,          // ...
    0b10000000
};

uint8_t digit_1 = 0;
uint8_t digit_2 = 0;

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Display decimal counter values on SSD (Seven-segment 
 *           display) when 16-bit Timer/Counter1 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Configure SSD signals
    SEG_init();

    // Test of SSD: display number '3' at position 0
    SEG_update_shift_regs(0b00000000, 0b11110000);
    SEG_clear();
    // Configure 16-bit Timer/Counter1 for Decimal counter
    // Set the overflow prescaler to 262 ms and enable interrupt
    TIM1_overflow_262ms();
    TIM1_overflow_interrupt_enable();
    TIM0_overflow_4ms();
    TIM0_overflow_interrupt_enable();


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
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
uint8_t digit1 = 0; // showed number on 1st dig.
uint8_t digit2 = 0; // showed number on 2nd dig.
ISR(TIMER1_OVF_vect){ // slower timer - counting 00-59
    digit1++; // increment 1st dig.
    if (digit1 == 10){ // 1st dig. overflow
        digit1 = 0; // reset 1st dig
        digit2++;   // increment 2nd dig.
        if (digit2 == 6) digit2 = 0; //reset 2nd dig.
    }
}
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect){ // faster timer - disp. refresh
    static uint8_t position = 0;
    // refresh 1st digit
    if (position == 0){ SEG_update_shift_regs(digit1,0;
    } // refresh 2nd digit
    else{ SEG_update_shift_regs(digit2,1); 
    }

    position++; // increment refreshed dig. position
    if (position > 1) position = 0; // reset dig. position at the end
}