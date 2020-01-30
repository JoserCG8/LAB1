/*
 * File:   LAB1OTRO.c
 * Author: Roberto
 *
 * Created on January 24, 2020, 11:28 AM
 */



// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (RC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
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
#define _XTAL_FREQ 8000000
void conf (void);
void delay (unsigned int ms);
void iniciando (void);
void antirebote1 (void);
void antirebote2 (void);




void main(void) {
conf();
inicio:
if (PORTDbits.RD5 == 1){
    iniciando();
    while (1){
        if (PORTDbits.RD7==1){
            antirebote1();
        }
        
        if (PORTDbits.RD6==1){
            antirebote2();
        }
        
        if (PORTDbits.RD5 == 1){
            goto inicio;}
           
        }



    }
return; 
}
    

   
    
    

void iniciando (void){
    PORTC = 0b00000110; // aqui hacemos las distribuciones para poder observar observar el conteo regresivo
    PORTEbits.RE0 = 1;
    PORTEbits.RE1 = 0;
    PORTEbits.RE2 = 0;
    delay(50);
    PORTC  = 0b00010010;
    PORTEbits.RE0 = 0;
    PORTEbits.RE1 = 1;
    PORTEbits.RE2 = 0;
    delay(50);
    PORTC  = 0b01001111;
    PORTEbits.RE0 = 0;
    PORTEbits.RE1 = 0;
    PORTEbits.RE2 = 1;
    delay(50);
    PORTC  = 0b00000000;
    PORTEbits.RE0 = 0;
    PORTEbits.RE1 = 0;
    PORTEbits.RE2 = 0;   
    PORTDbits.RD0 = 0;
    PORTDbits.RD1 = 0;
}

//configuraciones iniciales 
void conf (void){
    OSCCON = 0b1001100;
    ANSEL  = 0;
    ANSELH = 0;
    PORTC  = 0;
    PORTD  = 0;
    PORTA  = 0x1;
    PORTB  = 0x1;
    PORTE  = 0;
    TRISA  = 0;
    TRISB  = 0;
    TRISC  = 0;
    TRISE  = 0;
    TRISDbits.TRISD7 = 1;
    TRISDbits.TRISD6 = 1;
    TRISDbits.TRISD5 = 1;
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    PORTDbits.RD3 = 1;
  
  }

void delay (unsigned int ms){
    for(int i = 0; i<ms; i++){
        for(int j = 0; j<255; j++);
    }
}

void antirebote1 (void){
    if (PORTDbits.RD7 == 0){
           PORTA = PORTA*2;
            if (PORTA ==0b10000000){
                PORTA = 0b00000001;
                PORTC = 0b01001111;
                PORTDbits.RD0 = 1;
                PORTDbits.RD1 = 0;
                PORTA = 0b00000001;
                PORTB = 0b00000001;
                
             
                
            }
 
                
            }
}

void antirebote2 (void){
    if (PORTDbits.RD6==0){
        PORTB = PORTB * 2 ;
        if (PORTB == 0b10000000){
            PORTB = 0b00000001;
            PORTC = 0b00010010;
            PORTDbits.RD0 = 0;
            PORTDbits.RD1 = 1;
            PORTA = 0b00000001;
            PORTB = 0b00000001;
            
            
            
        
    }
    }
}