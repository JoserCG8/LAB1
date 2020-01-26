/*
 * File:   LAB1OTRO.c
 * Author: Roberto
 *
 * Created on January 24, 2020, 11:28 AM
 */



// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = EXTRC_CLKOUT// Oscillator Selection bits (RC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void conf (void);
void delay (unsigned int ms);

void main(void) {
conf ();
    while (1)
        if (PORTDbits.RD5 == 1)   //Revisa el boton de inicio y si este tiene un 1 procedera hacer el conteo regresivo del display
        { PORTC = 0b11110010;
        delay();
        PORTC  = 0b11011010;
        delay()
        PORTC  = 0b01100000;
        delay ();
        PORTC  = 0b11111100;
        delay ();  
        PORTEbits.RE0 = 1;
        PORTEbits.RE1 = 0;
        PORTEbits.RE2 = 0;
        
        delay();
        PORTEbits.RE0 = 0;
        PORTEbits.RE1 = 1;
        PORTEbits.RE2 = 0;
        
        delay();
        PORTEbits.RE0 = 0;
        PORTEbits.RE1 = 0;
        PORTEbits.RE2 = 0;
       
        
        }
    return;
}

//configuraciones iniciales 
void conf (void){
    ANSEL  = 0;
    ANSELH = 0;
    PORTC  = 0;
    PORTD  = 0;
    PORTA  = 0;
    PORTB  = 0;
    PORTE  = 0;
    TRISA  = 0;
    TRISB  = 0;
    TRISC  = 0;
    TRISE  = 0;
    TRISDbits.TRISD7 = 1;
    TRISDbits.TRISD6 = 1;
    TRISDbits.TRISD5 = 1;
    
  }