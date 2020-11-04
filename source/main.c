/*	Author: Tinghui Song
 *  Partner(s) Name: none
 *	Lab Section:24
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



enum States {Start, Seq1a, Seq1b, Seq2a, Seq2b, Seq2c} State;


void Tick()
{
    unsigned char tempA = ~PINA;
    switch(State){ //transitions
        case Start:
		State = Seq1a;
            break;
	case Seq1a:
		State = (tempA)Seq2a:Seq1b;
		break;
	case Seq1b:
		State = (tempA)Seq2a:Seq1a;
		break;
	case Seq2a:
		State = (tempA)Seq1a:Seq2b;
		break;
	case Seq2b:
		State = (tempA)Seq1a:Seq2c;
		break;
	case Seq2c:
		State = (tempA)Seq1a:Seq2a;
		break;
        default:
            break;
    }
    switch(State){ //Actions
        case Start:
            break;
	case Seq1a:
		PORTB = 0x15;
		break;
	case Seq1b:
		PORTB = 0x2A;
		break;
	case Seq2a:
		PORTB = 0x03;
		break;
	case Seq2b:
		PORTB = 0x0C;
		break;
	case Seq2c:
		PORTB = 0x30;
		break;
        default:
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;  PORTA = 0xFF;
    DDRB = 0xFF;  PORTB = 0x00;

    State = Start;

    /* Insert your solution below */
    while (1) {
        Tick();
    }
    return 1;
}
