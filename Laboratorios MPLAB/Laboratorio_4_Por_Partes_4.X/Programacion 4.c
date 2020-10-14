/*
 * File:   Programacion 4.c
 * Author: Miguel
 *
 * Created on 3 de octubre de 2020, 02:04 PM
 */

#include <xc.h>

int conts=2;
int Paso=0;

void Iniciar_Puertos (void);
void Configuracion_Registros (void);
void Configuracion_TMR0 (void);
void Semaforo_Normal (void);
void Paso_Peatonal (void);

void main(void) 
{
    Iniciar_Puertos ();
    Configuracion_Registros ();
    Configuracion_TMR0 ();
    TMR0H=(3036)>>8;
    TMR0L=3036;
    
    while (1)
    {
        if (Paso==0)
        {
            Semaforo_Normal ();
        }
        else
        {
            Paso_Peatonal ();
        }
    }    
    return;
}
void Iniciar_Puertos (void)
{
    ADCON1=15;
    TRISB=1;
    PORTB=160;
}
void Configuracion_Registros (void)
{
    INTCONbits.GIE=0;
    INTCONbits.INT0IE=1;
    INTCON2bits.INTEDG0=1;
    INTCONbits.INT0IF=0;
    INTCONbits.GIE=1;
}
void Configuracion_TMR0 (void)
{
    INTCONbits.GIE=0;
    T0CONbits.T0CS=0;
    T0CONbits.PSA=0;
    T0CONbits.T0PS=3;
    T0CONbits.T08BIT=0;
    T0CONbits.TMR0ON=1;
//    T0CON=128;  //T0SE=0; 144 con T0SE=1;
    INTCONbits.TMR0IF=0;
    INTCONbits.TMR0IE=1;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
}
void Semaforo_Normal (void)
{
    if (conts%2==0)
    {
        PORTBbits.RB4=1;
        PORTBbits.RB5=0;
        PORTBbits.RB6=1;
        PORTBbits.RB7=0;
    }
    else
    {
        PORTBbits.RB4=0;
        PORTBbits.RB5=1;
        PORTBbits.RB6=0;
        PORTBbits.RB7=1;
    }
}
void Paso_Peatonal (void)
{
    conts=0;
    TMR0H=3036>>8;
    TMR0L=3036;
    while (conts3<15)
    {
        PORTBbits.RB4=1;
        PORTBbits.RB5=0;
        PORTBbits.RB6=1;
        PORTBbits.RB7=0;
    }
    conts=2;
    Paso=0;
}
void __interrupt() interrupciones(void)
{
    if (INTCONbits.INT0IF==1)
    {
        Paso=1;
        INTCONbits.INT0IF=0;
    }
    if (INTCONbits.TMR0IF==1)
    {
        conts++;
        TMR0H=3036>>8;
        TMR0L=3036;
        INTCONbits.TMR0IF=0;
    }
}
//TMR0 está en 1s