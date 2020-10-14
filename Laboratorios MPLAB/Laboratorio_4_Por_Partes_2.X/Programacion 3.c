/*
 * File:   Programacion.c
 * Author: Miguel
 *
 * Created on 30 de septiembre de 2020, 05:21 PM
 */

#include <xc.h>

int cont10ms=0;

void Configuracion_TMR0 (void);
void PWM_50 (void);
void PWM_80 (void);

void main(void) 
{
    ADCON1=15;
    TRISB=4;
    PORTB=0;
    
    Configuracion_TMR0 ();
    TMR0H=55536>>8;
    TMR0L=55536;
    
    while (1)
    {
        if (PORTBbits.RB2==1)
        {
            PWM_50 ();
            PWM_80 ();
        }
        else
        {
            PORTB=0;
            cont10ms=0;
        }
    }    
    return;
}
void Configuracion_TMR0 (void)
{
    INTCONbits.GIE=0;
    INTCONbits.PEIE=0;
    T0CON=136;
    INTCONbits.TMR0IE=1;
    INTCONbits.TMR0IF=0;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
}
void PWM_50 (void)
{
    if (cont10ms==10)
    {
        cont10ms=0;
    }
    else if (cont10ms>=5&&cont10ms<10)
    {
        PORTBbits.RB0=0;
    }
    else if (cont10ms<5||cont10ms==10)
    {
        PORTBbits.RB0=1;
    }
}
void PWM_80 (void)
{
    if (cont10ms>=8&&cont10ms<10)
    {
        PORTBbits.RB1=0;
    }
    else if (cont10ms<8||cont10ms==10)
    {
        PORTBbits.RB1=1;
    }  
}
void __interrupt() interrupciones(void)
{
    if (INTCONbits.TMR0IF==1)
    {
        cont10ms++;
        TMR0H=55536>>8;
        TMR0L=55536;
        INTCONbits.TMR0IF=0;
    }
}
//TMR0 está en 10 ms=0,01s