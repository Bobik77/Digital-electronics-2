EESchema Schematic File Version 4
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 61756127
P 3150 3850
F 0 "U1" H 2506 3896 50  0000 R CNN
F 1 "ATmega328P-PU" H 2506 3805 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 3150 3850 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3150 3850 50  0001 C CNN
	1    3150 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR02
U 1 1 61756EC7
P 3150 5350
F 0 "#PWR02" H 3150 5100 50  0001 C CNN
F 1 "GNDD" H 3154 5195 50  0000 C CNN
F 2 "" H 3150 5350 50  0001 C CNN
F 3 "" H 3150 5350 50  0001 C CNN
	1    3150 5350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 6175764B
P 3150 2350
F 0 "#PWR01" H 3150 2200 50  0001 C CNN
F 1 "+5V" H 3050 2500 50  0000 C CNN
F 2 "" H 3150 2350 50  0001 C CNN
F 3 "" H 3150 2350 50  0001 C CNN
	1    3150 2350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 61757EEE
P 3250 2350
F 0 "#PWR03" H 3250 2200 50  0001 C CNN
F 1 "+5V" H 3300 2500 50  0000 C CNN
F 2 "" H 3250 2350 50  0001 C CNN
F 3 "" H 3250 2350 50  0001 C CNN
	1    3250 2350
	1    0    0    -1  
$EndComp
Text GLabel 3750 2650 2    50   Input ~ 0
SEG_DATA
Text GLabel 3750 4750 2    50   Input ~ 0
SEG_LATCH
Text GLabel 3750 5050 2    50   Input ~ 0
SEG_CLK
Text Notes 4050 4350 0    50   ~ 0
SEG_DATA, SEG_LATCH, SEG_CLK,\nSW1, SW2, SW3\nare signals to multifunctions shield\n(see next page)
Text GLabel 3750 3650 2    50   Input ~ 0
SW1
Text GLabel 3750 3750 2    50   Input ~ 0
SW2
Text GLabel 3750 3850 2    50   Input ~ 0
SW3
$EndSCHEMATC
