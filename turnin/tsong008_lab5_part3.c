/*	Author: Tinghui Song
 *  Partner(s) Name: none
 *	Lab Section:24
 *	Assignment: Lab #5  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *          
 *  	Demo Link: https://drive.google.com/file/d/1ck6jtJBVAqUiL7f16zIsQhdpaL4t95oP/view?usp=sharing
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



enum States {Start, Seq1_R, Seq1_P, Seq2_R, Seq2_P} State;


void Tick()
{
    unsigned char tempA = ~PINA;
    switch(State){ //transitions
        case Start:
		State = Seq1_R;
            	break;
	case Seq1_R:
		State = (tempA)? Seq1_P:Seq1_R;
		break;
	case Seq1_P:
		State = (!tempA)? Seq2_R:Seq1_P;
		break;
	case Seq2_R:
		State = (tempA)? Seq2_P:Seq2_R;
		break;
	case Seq2_P:
		State = (!tempA)? Seq1_R:Seq2_P;
		break;
        default:
            break;
    }
    switch(State){ //Actions
        case Start:
            break;
	case Seq1_R:
		PORTB = 0x15;
		break;
	case Seq2_R:
		PORTB = 0x2A;
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
