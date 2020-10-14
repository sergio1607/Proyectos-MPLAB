
#include <xc.h>
#define _XTAL_FREQ 4000000
#pragma config PLLDIV=1
#pragma config FOSC=XT_XT

int num=0;
char opc='A';
int Nant=0;
int Nact=0;
int x=0;
int y=0;
int cont=0;
int cont1=0;


void Configuracion_Registros (void);
void Temp (void);
void und (int);
void dec (int);
void main(void) 
{
    TRISA=9;
    TRISB=255;
    TRISC=0;
    TRISD=0;
    TRISE=8;
    PORTA=0;
    PORTB=0;
    PORTC=0;
    PORTD=0;
    PORTE=0;
    
    Configuracion_Registros ();
        
    while (1)
    {
        PORTC=6; // Rotar 0 para el teclado matricial.
        PORTC=5;
        PORTC=3;
        Temp ();
        switch (opc)
        {
            case '*':
            {
                PORTDbits.RD5=0;
                PORTDbits.RD6=1;
                for (int j = Nant; j>=0; j--)
                {
                    dec (j);
                    if (cont==0)
                    {
                        for (int i = Nact; i>=0; i--)
                        {
                            und (i);
                            __delay_ms(1000);
                        }
                        cont=1;
                    }
                    else
                    {
                    for (int i=9; i>=0; i--)
                        {
                            und (i);
                            Nact=i;
                            __delay_ms(1000);
                    
                        }
                    
                    }
                    
                }
                cont=0;
                Nant=0;
                Nact=0;
                num=0;
                cont1=0;
                PORTDbits.RD6=0;
                opc='0';
                break;
            }
            default:
            {
                if (cont1==1)
                {
                    x=num;
                    Nact=x;
                    und(Nact);
                    y=Nact;
                    cont1++;
                }
                else if (cont1%2==1)
                {
                    Nant=y;
                    dec(Nant);
                    x=num;
                    Nact=num;
                    und (Nact);
                    y=Nact;
                    cont1++;
                }
                break;
            }
            opc='A';
        }
    }
    return;
}
void Configuracion_Registros (void)
{
    // ADC
    ADCON0=0; // Seleccion del canal y encendido y apagado
    ADCON1=0X1B; // Voltaje de referencia y configurar puertos D/A
    ADCON2=148; //  Frecuencias y Justificacion 
    // Interrupts
    INTCONbits.GIE=0; // Apagar interrupciones Globales
    INTCONbits.INT0IE=1; // Interrupcion RB0
    INTCON3bits.INT1IE=1; // Interrupcion RB1
    INTCON3bits.INT2IE=1; // Interrupcion RB2
    INTCONbits.RBIE=1; // Interrupciones del RB4 al RB7
    INTCON2bits.INTEDG0=1; // Flanco de subida o bajada RB0
    INTCON2bits.INTEDG1=1; // Flanco de subida o bajada RB1
    INTCON2bits.INTEDG2=1; //Flanco de subida o bajada RB2  
    RCONbits.IPEN=1; //Activa la jerarquia de interrupciones
    INTCONbits.GIEH=1; // Activa la interrupciones de alta prioridad externas
    INTCONbits.GIEL=1; // Activa interrupciones de baja prioridad de perifericos 
    INTCON3bits.INT1IP=1; // Prioridad RB1 (alta)
    INTCON3bits.INT2IP=0; // Prioridad RB2 (baja)
    INTCON2bits.RBIP=0; // Prioridad del RB4 al RB7
    INTCON2bits.NOT_RBPU=0; // Activar resistencias de pull-up
    INTCONbits.INT0IF=0; // Bandera RB0
    INTCON3bits.INT1IF=0; // Bandera RB1
    INTCON3bits.INT2IF=0; // Bandera RB2
    INTCONbits.RBIF=0; // Banderas del RB4 al RB7
}
void Temp (void) // Funcion para evaluar temperatura con 60º
{
    ADCON0bits.ADON=1; 
    ADCON0bits.GO_DONE=1;
    while (ADCON0bits.GO_DONE==1)
    {
        float tempt=0;
        float temp=0;
        
        tempt=ADRESL+(ADRESH*256);
        temp=(tempt+1)*150/1024;
        
        if (temp>60)
        {
            PORTDbits.RD4=1;
            PORTDbits.RD7=1;
        }
        else
        {
            PORTDbits.RD4=0;
            PORTDbits.RD7=0;
        }
    }
    ADCON0bits.GO_DONE =  0; // termina el la conversion 
    ADCON0bits.ADON = 0; // Apaga el conversor ADC 
}
void und (int x) // Funcion para el display de las unidades
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
void dec (int y) // Funcion para el display de las decenas
{
    if (y==0)
    {
        PORTAbits.RA4=0;
        PORTAbits.RA5=0;
        PORTEbits.RE0=0;
        PORTEbits.RE1=0;
    }
    else if (y==1)
    {
        PORTAbits.RA4=1;
        PORTAbits.RA5=0;
        PORTEbits.RE0=0;
        PORTEbits.RE1=0;
    }
    else if (y==2)
    {
        PORTAbits.RA4=0;
        PORTAbits.RA5=1;
        PORTEbits.RE0=0;
        PORTEbits.RE1=0;
    }
    else if (y==3)
    {
        PORTAbits.RA4=1;
        PORTAbits.RA5=1;
        PORTEbits.RE0=0;
        PORTEbits.RE1=0;
    }
    else if (y==4)
    {
        PORTAbits.RA4=0;
        PORTAbits.RA5=0;
        PORTEbits.RE0=1;
        PORTEbits.RE1=0;
    }
    else if (y==5)
    {
        PORTAbits.RA4=1;
        PORTAbits.RA5=0;
        PORTEbits.RE0=1;
        PORTEbits.RE1=0;
    }
    else if (y==6)
    {
        PORTAbits.RA4=0;
        PORTAbits.RA5=1;
        PORTEbits.RE0=1;
        PORTEbits.RE1=0;
    }
    else if (y==7)
    {
        PORTAbits.RA4=1;
        PORTAbits.RA5=1;
        PORTEbits.RE0=1;
        PORTEbits.RE1=0;
    }
    else if (y==8)
    {
        PORTAbits.RA4=0;
        PORTAbits.RA5=0;
        PORTEbits.RE0=0;
        PORTEbits.RE1=1;
    }
    else if (y==9)
    {
        PORTAbits.RA4=1;
        PORTAbits.RA5=0;
        PORTEbits.RE0=0;
        PORTEbits.RE1=1;
    }
}
void __interrupt(high_priority) ISR_EX0_1(void) // Interrupciones de alta prioridad
{
    if (INTCONbits.INT0IF==1) // Mantenimiento
    {
        INTCONbits.INT0IF=0;
        for (int i=0; i<10; i++)
        {
            und(i);
            dec(i);
            __delay_ms(500);
        }
        und(0);
        dec(0);
        for (int i=0; i<3; i++)
        {
            PORTDbits.RD5=1;
            __delay_ms(300);
            PORTDbits.RD5=0;
            __delay_ms(300);
            PORTDbits.RD6=1;
            __delay_ms(300);
            PORTDbits.RD6=0;
            __delay_ms(300);
            PORTDbits.RD7=1;
            __delay_ms(300);
            PORTDbits.RD7=0;
            __delay_ms(300);            
        }
    }
    if (INTCON3bits.INT1IF==1) // Temperatura 
    {
        while (PORTDbits.RD4==1)
        {
            Temp ();
        }
        if (PORTBbits.RB2==0)
        {
            PORTDbits.RD7=0;
            INTCON3bits.INT1IF=0;            
        }
        else
        {
            PORTDbits.RD7=1;
        }
    }
}
void __interrupt (low_priority) ISR_RB(void) // Interrupciones de bajas prioridades
{
    if (INTCON3bits.INT2IF==1) // Pausa
    {
        while (PORTBbits.RB3==1)
        {
            PORTDbits.RD5=1;
        }
        if (PORTBbits.RB3==0)
        {
            INTCON3bits.INT2IF=0;
            PORTDbits.RD5=0;
        }
    }
    if (INTCONbits.RBIF==1) // Teclado matricial
    {
        cont1++;
        
        if (PORTCbits.RC0==0)
        {
            if (PORTBbits.RB4==0) {num=1;}
            if (PORTBbits.RB5==0) {num=4;}
            if (PORTBbits.RB6==0) {num=7;}
            if (PORTBbits.RB7==0) {opc='*';}
        }
        if (PORTCbits.RC1==0)
        {
            if (PORTBbits.RB4==0) {num=2;}
            if (PORTBbits.RB5==0) {num=5;}
            if (PORTBbits.RB6==0) {num=8;}
            if (PORTBbits.RB7==0) {num=0;}
        }
        if (PORTCbits.RC2==0)
        {
            if (PORTBbits.RB4==0) {num=3;}
            if (PORTBbits.RB5==0) {num=6;}
            if (PORTBbits.RB6==0) {num=9;}
            if (PORTBbits.RB7==0) {PORTAbits.RA5=1;}
        }
        while (PORTBbits.RB4==0||PORTBbits.RB5==0||PORTBbits.RB6==0||PORTBbits.RB7==0);
        INTCONbits.RBIF=0;
    }
}
// *Empieza, #pausa, led de encendido mientras funciona, más de 60° otro led rojo se enciende.
// Si se pulsa un botón en otro lado entra en mantenimiento, displays 1-9, leds intermitentes 3 veces.