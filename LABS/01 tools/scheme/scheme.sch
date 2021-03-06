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
L Device:R R1
U 1 1 615086A6
P 4800 2800
F 0 "R1" V 4593 2800 50  0000 C CNN
F 1 "220R" V 4684 2800 50  0000 C CNN
F 2 "" V 4730 2800 50  0001 C CNN
F 3 "~" H 4800 2800 50  0001 C CNN
	1    4800 2800
	0    1    1    0   
$EndComp
$Comp
L Device:LED D1
U 1 1 61508CE2
P 5250 2800
F 0 "D1" H 5243 2545 50  0000 C CNN
F 1 "GREEN" H 5243 2636 50  0000 C CNN
F 2 "" H 5250 2800 50  0001 C CNN
F 3 "~" H 5250 2800 50  0001 C CNN
	1    5250 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 2800 4650 2800
Wire Wire Line
	4950 2800 5100 2800
Wire Wire Line
	5400 2800 5550 2800
Wire Wire Line
	5550 2800 5550 2900
$Comp
L power:GNDD #PWR04
U 1 1 61509C8B
P 5550 2900
F 0 "#PWR04" H 5550 2650 50  0001 C CNN
F 1 "GNDD" H 5554 2745 50  0000 C CNN
F 2 "" H 5550 2900 50  0001 C CNN
F 3 "" H 5550 2900 50  0001 C CNN
	1    5550 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR02
U 1 1 6150A24F
P 3850 5000
F 0 "#PWR02" H 3850 4750 50  0001 C CNN
F 1 "GNDD" H 3854 4845 50  0000 C CNN
F 2 "" H 3850 5000 50  0001 C CNN
F 3 "" H 3850 5000 50  0001 C CNN
	1    3850 5000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 6150B696
P 3950 2000
F 0 "#PWR03" H 3950 1850 50  0001 C CNN
F 1 "+5V" H 3965 2173 50  0000 C CNN
F 2 "" H 3950 2000 50  0001 C CNN
F 3 "" H 3950 2000 50  0001 C CNN
	1    3950 2000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 6150BCF3
P 3850 2000
F 0 "#PWR01" H 3850 1850 50  0001 C CNN
F 1 "+5V" H 3865 2173 50  0000 C CNN
F 2 "" H 3850 2000 50  0001 C CNN
F 3 "" H 3850 2000 50  0001 C CNN
	1    3850 2000
	1    0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U1
U 1 1 61506EAF
P 3850 3500
F 0 "U1" H 4250 4950 50  0000 C CNN
F 1 "ATmega328P-AU" H 4250 2050 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3850 3500 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3850 3500 50  0001 C CNN
	1    3850 3500
	1    0    0    -1  
$EndComp
$EndSCHEMATC
