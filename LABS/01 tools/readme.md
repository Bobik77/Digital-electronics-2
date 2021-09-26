# Lab 1: Pavel Vaněk

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/Bobik77/Digital-electronics-2](https://github.com/Bobik77/Digital-electronics-2)


### Blink example

1. What is the meaning of the following binary operators in C?
   * `|`  Operátor log. součtu (OR)
   * `&`  Operátor log. součinu (AND)
   * `^`  Operátor log. výlučného součtu (XOR)
   * `~`  Operátor log. negace (NOT)
   * `<<` Operátor bitového posunu vlevo (left shift)
   * `>>`Operátor bitového posunu vpravo (right shift)

2. Complete truth table with operators: `|`, `&`, `^`, `~`

| **b** | **a** |**b or a** | **b and a** | **b xor a** | **not b** |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1| 1 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |


### Morse code

1. Listing of C code with syntax highlighting which repeats one "dot" and one "comma" on a LED:

```c
int main(void)
{
   
}
```


2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![scheme.png](scheme.png)