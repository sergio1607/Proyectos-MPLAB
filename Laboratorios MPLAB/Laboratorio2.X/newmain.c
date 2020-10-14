/*
 * File:   newmain.c
 * Author: sergi
 *
 * Created on 14 de agosto de 2020, 06:11 PM
 */
#include <xc.h>
#define _XTAL_FREQ 4000000
#include "pic18f4550.h"
void main(void) {
    
    PORTA = 0b00000000;
    PORTD = 0b00000000;
    TRISD = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    TRISAbits.RA4 = 1;
    
    int cont;
    inicio:
    
    if(PORTAbits.RA4 == 1 && cont == 0)
    {    
        
        PORTBbits.RB0 = 1;
        __delay_ms(500);
        PORTBbits.RB0 = 0;
        PORTBbits.RB1 = 1;
        __delay_ms(500);
        PORTBbits.RB1 = 0;
        PORTBbits.RB2 = 1;
        __delay_ms(500);
        PORTBbits.RB2 = 0;
        PORTBbits.RB3 = 1;
        __delay_ms(500);
        PORTBbits.RB3 = 0;
        PORTBbits.RB4 = 1;
        __delay_ms(500);
        PORTBbits.RB4 = 0;
        PORTBbits.RB5 = 1;
        __delay_ms(500);
        PORTBbits.RB5 = 0;
        PORTBbits.RB6 = 1;
        __delay_ms(500);
        PORTBbits.RB6 = 0;
        PORTBbits.RB7 = 1;
        __delay_ms(500);
        PORTBbits.RB7 =1;
        __delay_ms(500);
        PORTBbits.RB7 =0;
        PORTBbits.RB6 =1;
        __delay_ms(500);
        PORTBbits.RB6 =0;
        PORTBbits.RB5 =1;
        __delay_ms(500);
        PORTBbits.RB5 =0;
        PORTBbits.RB4 =1;
        __delay_ms(500);
        PORTBbits.RB4 =0;
        PORTBbits.RB3 =1;
        __delay_ms(500);
        PORTBbits.RB3 =0;
        PORTBbits.RB2 =1;
        __delay_ms(500);
        PORTBbits.RB2 =0;
        PORTBbits.RB1 =1;
        __delay_ms(500);
        PORTBbits.RB1 =0;
        PORTBbits.RB0 =1;
        __delay_ms(500);
        PORTBbits.RB0 =0;
        cont = 1;
        }
    else
    {
        PORTB = 0b00000000;
    }
        if(PORTAbits.RA4 == 1 && cont == 1)
        {
        PORTDbits.RD0 = 1;
        __delay_ms(2000);
        PORTDbits.RD1 = 1;
        __delay_ms(2000);
        PORTDbits.RD2 = 1;
        __delay_ms(2000);
        PORTDbits.RD3 = 1;
        __delay_ms(2000);
        PORTDbits.RD4 = 1;
        __delay_ms(2000);
        PORTDbits.RD5 = 1;
        __delay_ms(2000);
        PORTDbits.RD6 = 1;
        __delay_ms(2000);
        PORTDbits.RD7 = 1;
        __delay_ms(2000);
        PORTDbits.RD7 = 0;
        __delay_ms(2000);
        PORTDbits.RD6 = 0;
        __delay_ms(2000);
        PORTDbits.RD6 = 0;
         PORTDbits.RD5 = 0;
        __delay_ms(2000);
        PORTDbits.RD5 = 0;
         PORTDbits.RD4 = 0;
        __delay_ms(2000);
        PORTDbits.RD4 = 0;
         PORTDbits.RD3 = 0;
        __delay_ms(2000);
        PORTDbits.RD3 = 0;
         PORTDbits.RD2 = 0;
        __delay_ms(2000);
        PORTDbits.RD2 = 0;
         PORTDbits.RD1 = 0;
        __delay_ms(2000);
        PORTDbits.RD1 = 0;
        PORTDbits.RD0 = 0;
        __delay_ms(2000);
        PORTDbits.RD0 = 0;
        
        cont ++;
        
    }
    else
    {
        PORTD = 0b00000000;
    }
    if(PORTAbits.RA4 == 1 && cont == 2 ){
        
        //Numero 0 en BCD  0000
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =0;      
        __delay_ms(1000);
        // Numero 1 en BCD 0001
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 2 en BCD 0010
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 3 en BCD 0011
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 4 en BCD 0100
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 5 en BCD 0101
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 6 en BCD 0110
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =1; 
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 7 en BCD 0111
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =0;
        __delay_ms(1000);
        //Numero 8 en BCD 1000
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 9 en BCD 1001
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 10 en BCD 1010
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 11 en BCD 1011
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =0;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 12 en BCD 1100
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 13 en BCD 1101
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =0;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 14 en BCD 1110
        PORTCbits.RC0 =0;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        //Numero 15 en BCD 1111
        PORTCbits.RC0 =1;
        PORTCbits.RC1 =1;
        PORTCbits.RC2 =1;
        PORTCbits.RC4 =1;
        __delay_ms(1000);
        cont ++;
        PORTC = 0x00;
    }
    if(PORTAbits.RA4 == 1 && cont == 3){
        
        do{
            PORTCbits.RC7 = 1;
            __delay_ms(500);
            PORTCbits.RC7 = 0;
            __delay_ms(500);
        }
        while(PORTAbits.RA4 == 0);
        cont++;
        __delay_ms(200);
    }
    else{
    
        PORTCbits.RC7 = 0;
    }
    if(PORTAbits.RA4 == 1 && cont == 4){
        
        cont=0;
        goto inicio;
        
    }
    return;
}
 