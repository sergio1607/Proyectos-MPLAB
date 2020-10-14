/*
 * File:   Programacion 1.c
 * Author: Miguel
 *
 * Created on 3 de octubre de 2020, 02:04 PM
 */

#include <xc.h>

int dec=0;
int und=0;

void Iniciar_Puertos (void);
void Configuracion_TMR0 (void);
void Configuracion_Registros (void);
void EU (int);
void ED (int);

void main(void) 
{
    Iniciar_Puertos ();
    Configuracion_Registros ();
    Configuracion_TMR0 ();
    TMR0L=0;
    
    while (1)
    {
        und=TMR0L;
        if (und>=30)
        {
            PORTBbits.RB1=1;
            dec=3;
            und=und-30;
        }
        else if (und>=20)
        {
            PORTBbits.RB1=0;
            dec=2;
            und=und-20;
        }
        else if (und>=10)
        {
            PORTBbits.RB1=0;
            dec=1;
            und=und-10;
        }
        else if (und<10)
        {
            PORTBbits.RB1=0;
            dec=0;
        }
        EU (und);
        ED (dec);
    }    
    return;
}
void Iniciar_Puertos (void)
{
    ADCON1=15;
    TRISA=16;
    PORTA=0;
    TRISB=1;
    PORTB=0;
    TRISD=0;
    PORTD=0;
}
void EU (int x)
{
    if (x==0)
    {
        PORTDbits.RD0=0;
        PORTDbits.RD1=0;
        PORTDbits.RD2=0;
        PORTDbits.RD3=0;
    }
    else if (x==1)
    {
        PORTDbits.RD0=1;
        PORTDbits.RD1=0;
        PORTDbits.RD2=0;
        PORTDbits.RD3=0;
    }
    else if (x==2)
    {
        PORTDbits.RD0=0;
        PORTDbits.RD1=1;
        PORTDbits.RD2=0;
        PORTDbits.RD3=0;
    }
    else if (x==3)
    {
        PORTDbits.RD0=1;
        PORTDbits.RD1=1;
        PORTDbits.RD2=0;
        PORTDbits.RD3=0;
    }
    else if (x==4)
    {
        PORTDbits.RD0=0;
        PORTDbits.RD1=0;
        PORTDbits.RD2=1;
        PORTDbits.RD3=0;
    }
    else if (x==5)
    {
        PORTDbits.RD0=1;
        PORTDbits.RD1=0;
        PORTDbits.RD2=1;
        PORTDbits.RD3=0;
    }
    else if (x==6)
    {
        PORTDbits.RD0=0;
        PORTDbits.RD1=1;
        PORTDbits.RD2=1;
        PORTDbits.RD3=0;
    }
    else if (x==7)
    {
        PORTDbits.RD0=1;
        PORTDbits.RD1=1;
        PORTDbits.RD2=1;
        PORTDbits.RD3=0;
    }
    else if (x==8)
    {
        PORTDbits.RD0=0;
        PORTDbits.RD1=0;
        PORTDbits.RD2=0;
        PORTDbits.RD3=1;
    }
    else if (x==9)
    {
        PORTDbits.RD0=1;
        PORTDbits.RD1=0;
        PORTDbits.RD2=0;
        PORTDbits.RD3=1;
    }
}
void ED (int y)
{
    if (y==0)
    {
        PORTDbits.RD4=0;
        PORTDbits.RD5=0;
        PORTDbits.RD6=0;
        PORTDbits.RD7=0;
    }
    else if (y==1)
    {
        PORTDbits.RD4=1;
        PORTDbits.RD5=0;
        PORTDbits.RD6=0;
        PORTDbits.RD7=0;
    }
    else if (y==2)
    {
        PORTDbits.RD4=0;
        PORTDbits.RD5=1;
        PORTDbits.RD6=0;
        PORTDbits.RD7=0;
    }
    else if (y==3)
    {
        PORTDbits.RD4=1;
        PORTDbits.RD5=1;
        PORTDbits.RD6=0;
        PORTDbits.RD7=0;
    }
    else if (y==4)
    {
        PORTDbits.RD4=0;
        PORTDbits.RD5=0;
        PORTDbits.RD6=1;
        PORTDbits.RD7=0;
    }
    else if (y==5)
    {
        PORTDbits.RD4=1;
        PORTDbits.RD5=0;
        PORTDbits.RD6=1;
        PORTDbits.RD7=0;
    }
    else if (y==6)
    {
        PORTDbits.RD4=0;
        PORTDbits.RD5=1;
        PORTDbits.RD6=1;
        PORTDbits.RD7=0;
    }
    else if (y==7)
    {
        PORTDbits.RD4=1;
        PORTDbits.RD5=1;
        PORTDbits.RD6=1;
        PORTDbits.RD7=0;
    }
    else if (y==8)
    {
        PORTDbits.RD4=0;
        PORTDbits.RD5=0;
        PORTDbits.RD6=0;
        PORTDbits.RD7=1;
    }
    else if (y==9)
    {
        PORTDbits.RD4=1;
        PORTDbits.RD5=0;
        PORTDbits.RD6=0;
        PORTDbits.RD7=1;
    }
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
    T0CONbits.T0CS=1;
    T0CONbits.T0SE=0;
    T0CONbits.PSA=1;
    T0CONbits.T08BIT=1;
    T0CONbits.TMR0ON=1;
//    T0CON=128;  //T0SE=0; 144 con T0SE=1;
    INTCONbits.TMR0IF=0;
    INTCONbits.TMR0IE=1;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
}
void __interrupt() interrupciones(void)
{
    if (INTCONbits.INT0IF==1)
    {
        TMR0L--;
        INTCONbits.INT0IF=0;
    }
    if (INTCONbits.TMR0IF==1)
    {
        INTCONbits.TMR0IF=0;
    }
}
