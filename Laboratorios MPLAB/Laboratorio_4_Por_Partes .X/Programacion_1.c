/*
 * File:   Programacion 1.c
 * Author: Miguel
 *
 * Created on 3 de octubre de 2020, 02:04 PM
 */

#include <xc.h>

int cont0_1s=0; // Contador del timer 0 , cinfigurado en 0.1 s // Prescaler 2
int cont0_5s=0; // Contador del timer 1 , configurado a 0.5 s // Prescaler 8
int conts=0; // Contador de segundos
int contm=0; // Contador de minitus 
int decimas=0; // Variable para las decimas de segundo - Visualizar
int S=0; // Variable para los segundos - Visualizar
int DS=0; // Variables para los decasegundos o decenas de segundos - Visualizar
int min=0; // Variable para minutos - Visualizar
int Dmin=0; // Variable para decaminutos - Visualizar

void Iniciar_Puertos (void);
void Configuracion_TMR0 (void);
void Configuracion_TMR1 (void);
void Datos_Reloj (void);
void Pintar_Reloj (void);
void Dm (int);
void m (int);

void main(void) 
{
    Iniciar_Puertos ();
    Configuracion_TMR0 ();
    TMR0H=(15536)>>8;
    TMR0L=15536;
    Configuracion_TMR1 ();
    TMR1H=(3036)>>8;
    TMR1L=3036;
    
    while (1)
    {
        Datos_Reloj ();
        Pintar_Reloj ();
    }    
    return;
}
void Iniciar_Puertos (void)
{
    ADCON1=15;
    TRISA=0;
    PORTA=0;
    TRISB=0;
    PORTB=0;
    TRISC=0;
    PORTC=0;
    TRISD=0;
    PORTD=0;
}
void Configuracion_TMR0 (void)
{
    INTCONbits.GIE=0;
    T0CONbits.T0CS=0;// Para determinar si es reloj interno o contador externo pin RA3
    T0CONbits.PSA=0; // Habilita Prescaler
    T0CONbits.T0PS=0; // Prescaler 2 
    T0CONbits.T08BIT=0; // Seleccion de bits - 16 bits
    T0CONbits.TMR0ON=1; // Encender el Timer
//    T0CON=128;  //T0SE=0; 144 con T0SE=1;
    INTCONbits.TMR0IF=0; // Bajar banderas de interrupciones  
    INTCONbits.TMR0IE=1; // Habilitacion de la interrupcion
    INTCONbits.GIE=1; // Encender interrupciones globales
    INTCONbits.PEIE=1; // Encender interrupciones de perifericos
}
void Configuracion_TMR1 (void)
{
    INTCONbits.GIE=0;
    INTCONbits.PEIE=0;
    T1CONbits.TMR1CS=0;
    T1CONbits.T1CKPS=3;
    T1CONbits.T1RD16=1;
    T1CONbits.TMR1ON=1;
//  T1CON=249;  //T1OSCEN=1;  214 con T1OSCEN=0;
    PIE1bits.TMR1IE=1;
    PIR1bits.TMR1IF=0;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
}
void Datos_Reloj (void)
{
    if (cont0_1s==10)
    {
        cont0_1s=0;
    }
    decimas=cont0_1s;
    if (cont0_5s==2)
    {
        conts++;
        cont0_5s=0;
    }
    if (conts==60)
    {
        contm++;
        conts=0;
    }
    if (conts>=50)
    {
        DS=5;
        S=conts-50;
    }
    else if (conts>=40)
    {
        DS=4;
        S=conts-40;
    }
    else if (conts>=30)
    {
        DS=3;
        S=conts-30;
    }
    else if (conts>=20)
    {
        DS=2;
        S=conts-20;
    }
    else if (conts>=10)
    {
        DS=1;
        S=conts-10;
    }
    else if (conts<10)
    {
        DS=0;
        S=conts;
    }
    if (contm>=90)
    {
        Dmin=9;
        min=contm-90;
    }
    else if (contm>=80)
    {
        Dmin=8;
        min=contm-80;
    }
    else if (contm>=70)
    {
        Dmin=7;
        min=contm-70;
    }
    else if (contm>=60)
    {
        Dmin=6;
        min=contm-60;
    }
    else if (contm>=50)
    {
        Dmin=5;
        min=contm-50;
    }
    else if (contm>=40)
    {
        Dmin=4;
        min=contm-40;
    }
    else if (contm>=30)
    {
        Dmin=3;
        min=contm-30;
    }
    else if (contm>=20)
    {
        Dmin=2;
        min=contm-20;
    }
    else if (contm>=10)
    {
        Dmin=1;
        min=contm-10;
    }
    else if (contm<10)
    {
        Dmin=0;
        min=contm;
    }
}
void Pintar_Reloj (void)
{
    PORTA=decimas;
    PORTB=S;
    PORTC=DS;
    m (min);
    Dm (Dmin);
}
void m (int x)
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
void Dm (int y)
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
void __interrupt() interrupciones(void)
{
    if (INTCONbits.TMR0IF==1)
    {
        cont0_1s++;
        TMR0H=15536>>8;
        TMR0L=15536;
        INTCONbits.TMR0IF=0;
    }
    if (PIR1bits.TMR1IF==1)
    {
        cont0_5s++;
        TMR1H=3036>>8;
        TMR1L=3036;
        PIR1bits.TMR1IF=0;
    }
}
//TMR0 est� en 100 ms=0,1s
//TMR1 est� en 0.5 s