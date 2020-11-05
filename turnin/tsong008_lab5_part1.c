/*	Author: Tinghui Song
 *  Partner(s) Name: none
 *	Lab Section:24
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://drive.google.com/file/d/1N4OPCcdHdWdhx8PDZpOk-dOrFQrYYn-v/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

    /* Insert your solution below */
	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;
    while (1) {
	tempA =~ PINA & 0x0F;
	if(tempA == 0x00){
		tempC = 0x40;
	}
	else if(tempA <= 0x02){
		tempC = 0x60;
	}
	else if (tempA <= 0x04){
		tempC = 0x70;
	}
	else if (tempA <= 0x06){
		tempC = 0x38;
	}
	else if (tempA <= 0x09){
		tempC = 0x3C;
	}
	else if (tempA <= 0x0C){
		tempC = 0x3E;
	}
	else{
		tempC = 0x3F;
	}
	PORTC = tempC;
    }
    return 1;
}
