

#include <xc.h>

void main(void) 
{
    TRISA=15;
    TRISB=0;
    PORTB=0;
    TRISC=7;
    TRISC=0;
    TRISD=0;
    PORTD=0;
    
    while (1)
    {        
        ADCON1=0x0B;
    
        ADCON0=0;  //Selección de Canal 0, y configuración inicial de conversor análogo
    
        ADCON2bits.ACQT=2;  //Configuración estándar de tiempo de muestreo con 4MHz de frecuencia
        ADCON2bits.ADCS=4;  //Configuración estándar de tiempo de conversión con 4MHz de frecuencia
        ADCON2bits.ADFM=1;  //Jutificación, derecha=1 y izquierda=0
    
        ADCON0bits.ADON=1;  //Encendido de módulo de conversión 
    
        ADCON0bits.GO_DONE=1;  //Encendido de conversión, Convirtiendo=1 y Finalizado=0 
        while (ADCON0bits.GO_DONE==1)
        {
            float vt=0;
            float aux=0;
            float voltaje=0;
            
            vt=ADRESL+(ADRESH*256);
            voltaje=(vt+1)*50/1024;
            if (voltaje>=50)
            {
                PORTDbits.RD0=1;
                PORTDbits.RD1=0;
                PORTDbits.RD2=1;
                PORTDbits.RD3=0;
                aux=voltaje-50;
            }
            else if (voltaje>=40)
            {
                PORTDbits.RD0=0;
                PORTDbits.RD1=0;
                PORTDbits.RD2=1;
                PORTDbits.RD3=0;
                aux=voltaje-40;
            }
            else if (voltaje>=30)
            {
                PORTDbits.RD0=1;
                PORTDbits.RD1=1;
                PORTDbits.RD2=0;
                PORTDbits.RD3=0;
                aux=voltaje-30;
            }
            else if (voltaje>=20)
            {
                PORTDbits.RD0=0;
                PORTDbits.RD1=1;
                PORTDbits.RD2=0;
                PORTDbits.RD3=0;
                aux=voltaje-20;
            }
            else if (voltaje>=10)
            {
                PORTDbits.RD0=1;
                PORTDbits.RD1=0;
                PORTDbits.RD2=0;
                PORTDbits.RD3=0;
                aux=voltaje-10;
            }
            else //0 Voltios
            {
                PORTDbits.RD0=0;
                PORTDbits.RD1=0;
                PORTDbits.RD2=0;
                PORTDbits.RD3=0;
                aux=voltaje;
            }
            if (aux>=9)
            {
                PORTDbits.RD4=1;
                PORTDbits.RD5=0;
                PORTDbits.RD6=0;
                PORTDbits.RD7=1;
            }
            else if (aux>=8)
            {
                PORTDbits.RD4=0;
                PORTDbits.RD5=0;
                PORTDbits.RD6=0;
                PORTDbits.RD7=1;
            }
            else if (aux>=7)
            {
                PORTDbits.RD4=1;
                PORTDbits.RD5=1;
                PORTDbits.RD6=1;
                PORTDbits.RD7=0;
            }
            else if (aux>=6)
            {
                PORTDbits.RD4=0;
                PORTDbits.RD5=1;
                PORTDbits.RD6=1;
                PORTDbits.RD7=0;
            }
            else if (aux>=5)
            {
                PORTDbits.RD4=1;
                PORTDbits.RD5=0;
                PORTDbits.RD6=1;
                PORTDbits.RD7=0;
            }
            else if (aux>=4)
            {
                PORTDbits.RD4=0;
                PORTDbits.RD5=0;
                PORTDbits.RD6=1;
                PORTDbits.RD7=0;
            }
            else if (aux>=3)
            {
                PORTDbits.RD4=1;
                PORTDbits.RD5=1;
                PORTDbits.RD6=0;
                PORTDbits.RD7=0;
            }
            else if (aux>=2)
            {
                PORTDbits.RD4=0;
                PORTDbits.RD5=1;
                PORTDbits.RD6=0;
                PORTDbits.RD7=0;
            }
            else if (aux>=1)
            {
                PORTDbits.RD4=1;
                PORTDbits.RD5=0;
                PORTDbits.RD6=0;
                PORTDbits.RD7=0;
            }
            else if (aux>=0)
            {
                PORTDbits.RD4=0;
                PORTDbits.RD5=0;
                PORTDbits.RD6=0;
                PORTDbits.RD7=0;
            }
            if (voltaje>25)
            {
                PORTBbits.RB0=1;
            }
            else
            {
                PORTBbits.RB0=0;
            }
        }
        
        
        ADCON0bits.GO_DONE=0;
        ADCON0bits.ADON=0;
        ADCON0bits.CHS=1;  //Selección del canal 1 en el puerto AN1
        ADCON1bits.VCFG0=1; //Toma voltaje de referencia positivo en el puerto AN3
        ADCON0bits.ADON=1;
        ADCON0bits.GO_DONE=1;
        
        while (ADCON0bits.GO_DONE==1)
        {
            float tempt=0;
            float temperatura=0;
            float temf=0;
            
            tempt=ADRESL+(ADRESH*256);
            temperatura=(tempt+1)*150/1024;
            temf=(temperatura*9/5)+32;
            if (temf>176)
            {
                PORTBbits.RB1=1;
                if (PORTCbits.RC0==1&&PORTCbits.RC1==1&&PORTCbits.RC2==0)
                {
                    PORTBbits.RB2=1;
                }
                else if (PORTCbits.RC0==0&&PORTCbits.RC1==0&&PORTCbits.RC2==1)
                {
                    PORTBbits.RB2=1;
                }
                else
                {
                    PORTBbits.RB2=0;
                }
            }
            else
            {
                if (PORTCbits.RC0==1&&PORTCbits.RC1==0&&PORTCbits.RC2==1)
                {
                    PORTBbits.RB2=1;
                }
                else if (PORTCbits.RC0==0&&PORTCbits.RC1==1&&PORTCbits.RC2==0)
                {
                    PORTBbits.RB2=1;
                }
                else
                {
                    PORTBbits.RB2=0;
                }
                PORTBbits.RB1=0;
            }
        }
    }    
    return;
}