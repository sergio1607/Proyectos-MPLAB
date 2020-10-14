#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    
    int adc;
    float volt;
    
    
    PORTC = 0x00;
    PORTD = 0x00;
    PORTB = 0x00;
    TRISA = 0xFF;
    TRISB = 0x00;
    TRISC = 0x00;
    
    //Inicializo el puerto RA2 en 0, y lo declaro como entrada.
    PORTAbits.RA2 = 0;
    TRISAbits.RA2 = 1;
    
    // Configurar el Puerto AN2 = RA2 como la entrada analogica
    ADCON0bits.CHS3 = 0;
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS1 = 1;
    ADCON0bits.CHS0 = 0;
    // Declarar el Rango Analogico de 0-5v
    ADCON1bits.VCFG1 = 0;
    ADCON1bits.VCFG0 = 0;
    //Declarar A2 como  pin analogo 
    ADCON1bits.PCFG3 = 1;
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG1 = 0;
    ADCON1bits.PCFG0 = 0; 
    //Justificacion hacia la derecha.
    ADCON2bits.ADFM = 1;
    // Tiempo de adquisicion 4TAD
    ADCON2bits.ACQT2 = 0;
    ADCON2bits.ACQT1 = 1;
    ADCON2bits.ACQT0 = 0;
    //Seleccion de conversion A/D ; Fosc/4
    ADCON2bits.ADCS2 = 1;
    ADCON2bits.ADCS1 = 0;
    ADCON2bits.ADCS0 = 0;
    //Inicio del conversor
    ADCON0bits.ADON = 1;
    
    while(1){
        ADCON0bits.GO_DONE = 1; // Conversion en progreso
        
        while(ADCON0bits.GO_DONE =1){
        
            adc = ADRESH;
            adc = adc>>8;
            adc = adc+ADRESL; // ADC ya estara organizado de forma significativa
            volt = (adc*5.0)/(1024.0); // La variable volt tendra valores entre 0-5
           
            //PORT B del RB0 al RB3 Unidad de la decena - del RB4 al RB7 
            
            if(volt == 0.1){
                PORTB = 0b00010000;
            }
            
            else if(volt==0.2){
            
                 PORTB = 0b00100000;
            }
            else if(volt == 0.3){
                PORTB = 0b00110000;
            }
             else if(volt == 0.4){
                PORTB = 0b01000000;
                 
            }
             else if(volt == 0.5){
                PORTB = 0b01010000;
            }
             else if(volt == 0.6){
                PORTB = 0b01100000;
            }
             else if(volt == 0.7){
                 PORTB = 0b01110000;
            }
             else if(volt == 0.8){
                 PORTB = 0b10000000;
            }
             else if(volt == 0.9){
                 PORTB = 0b10010000;
            }
             else if(volt == 1.0){
                 PORTB = 0b00000001;
            }
             else if(volt == 1.1){
                 PORTB = 0b00010001;
            }
            else if(volt == 1.2){
                PORTB = 0b00100001;
            }
            else if(volt == 1.3){
            
                PORTB = 0b00110001;
            }
            else if(volt == 1.4){
            
                PORTB = 0b01000001;
             
            }
            else if(volt == 1.5){
            
                PORTB = 0b01010001;
            
            }
            else if(volt == 1.6){
            
                PORTB = 0b01100001;
            
            }
            else if(volt == 1.7){
            
                PORTB = 0b01110001;
            
            }
            else if(volt == 1.8){
            
                PORTB = 0b10000001;
            
            }
            else if(volt == 1.9){
            
                PORTB = 0b10010001;
            }
            else if(volt == 2.0){
            
                PORTB = 0b00000010;
            
            }
            else if(volt == 2.1){
            
                PORTB = 0b00010010;
            }
            else if(volt == 2.2){
            
                PORTB = 0b00100010;
           
            }
            else if(volt == 2.3){
            
                PORTB = 0b00110010;
                
            }
            else if(volt == 2.4){
            
                PORTB = 0b01000010;
            }
            else if(volt == 2.5){
            
                PORTB = 0b01010010;
            
            }
            else if(volt == 2.6){
           
                PORTB = 0b01100010;
            
            }
            else if(volt == 2.7){
            
                PORTB = 0b01110010;
            
            }
            else if(volt == 2.8){
            
                PORTB = 0b10000010;
            }
            else if(volt == 3.0){
            
                PORTB = 0b00000011;
            }
            else if(volt == 3.1){
            
                PORTB = 0b00010011;
            }
            else if(volt == 3.2){
            
                PORTB = 0b00100011;
            }
            else if(volt == 3.3){
             
                PORTB = 0b00110011;
            }    
            else if(volt == 3.4){
            
                PORTB = 0b01000011;
            }
            else if(volt == 3.5){
            
                PORTB = 0b01010011;
            
            }
            else if(volt == 3.6){
            
                PORTB = 0b01100011;
            }
            else if(volt == 3.7){
            
                PORTB = 0b01110011;
            }
            else if(volt == 3.8){
            
                PORTB = 0b10000011;
            }
            else if(volt == 3.9){
            
                PORTB = 0b10010011;
                
            }
            else if(volt == 4.0){
            
                PORTB = 0b00000100;
                
            }
            else if(volt == 4.1){
                
                PORTB = 0b00010100;
            }
            else if(volt == 4.2){
            
                PORTB = 0b00100100;
            
            }
            else if(volt == 4.3){
            
                PORTB = 0b00110100;
            }
            else if(volt == 4.4){
                
                PORTB = 0b01000100;
            }
            else if(volt == 4.5){
            
                PORTB = 0b01010100;            
            }
            else if(volt == 4.6){
            
                PORTB = 0b01100100;
            }
            else if(volt == 4.7){
            
                PORTB = 0b01110100;
            }
            else if(volt == 4.8){
            
                PORTB = 0b10000100;
            }
            else if(volt == 4.9){
            
                PORTB = 0b10010100;
            }
            else if(volt == 5.0){
            
                PORTB = 0b00000101; 
            }
        }
    }
    
    
    return;
}
