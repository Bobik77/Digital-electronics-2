# Lab 3: Pavel Vaněk

Link to my `Digital-electronics-2` GitHub repository:

   [https://github.com/Bobik77/Digital-electronics-2](https://github.com/Bobik77/Digital-electronics-2)


### Data types in C

1. Complete table.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | -128,127, ...,127 | Signed 8-bit integer |
| `uint16_t` | 16 | 0,1, ..., 65535 | Unsigned 16-b integer |
| `int16_t`  | 16 | -32768, ..., 32766,32767 | Signed 16-b integer |
| `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | none | - | No value expression |


### GPIO library

1. In your words, describe the difference between the declaration and the definition of the function in C.
   * Function declaration - Deklaruje compileru název, vstupní parametry funkcea a jak funkci volat. Soubor s deklaracemi se nazývá header a má příponu "*.h"
   * Function definition - definuje samotné tělo funkce - tj. jednotlivé příkazy, které se vykonají při zavolání funkce. Soubory s definicí funkce mají přípou "*.c"

2. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Use function from your GPIO library. Let the push button is connected to port D:

```c
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
```


### Traffic light

1. Scheme of traffic light application with one red/yellow/green light for cars and one red/green light for pedestrians. Connect AVR device, LEDs, resistors, one push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![Traffic light](traffic_light.png)