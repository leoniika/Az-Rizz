/*
 * j6.c
 * Created: 11/26/2024 9:46:15 AM
 * Author: Nazanin
 */
 
//analog to digital
//vref -> max  S1-0 S0-1 LAR-0 S214 Avcc 
/* ADCH  ADCL unsign char -> int data
v -> float d = ADCW    
START CONVERTION (WHILE)
ADIF 0      */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{

unsigned char strl [5];

//MUX = 0000 input
ADMUX &= ~(1 << MUX0);
ADMUX &= ~(1 << MUX1);
ADMUX &= ~(1 << MUX2);
ADMUX &= ~(1 << MUX3);
ADMUX &= ~(1 << MUX4);

ADMUX |= (1 << REFS0);
ADMUX &= ~(1 << REFS1); //Vcc

ADMUX &= ~(1 << ADLAR);

ADCSRA &= ~(1 << ADSC);
ADCSRA &= ~(1 << ADATE); //Auto Triggering 
ADCSRA &= ~(1 << ADIF); //Interrupt Flag
ADCSRA &= ~(1 << ADIE); //Interrupt Enable

ADCSRA &= ~(1 << ADPS0);   //nerkh tagsim clock
ADCSRA |= ((1 << ADPS1) | (1 << ADPS2)); //0 1 1

ADCSRA |= (1 << ADEN); //on

lcd_init(16); 

while (1)
    { 
    unsigned int Data = 0;
    float v;

    ADMUX &= ~(1 << MUX0);
    ADMUX &= ~(1 << MUX1);
    ADMUX &= ~(1 << MUX2);
    ADMUX &= ~(1 << MUX3);

    ADCSRA |= (1 << ADEN);
    delay_us(10);

    ADCSRA |= (1 << ADSC);  //start = 1       
        
    while((ADCSRA & (1 << ADIF)) == 0);
    ADCSRA &= ~(1 << ADIF);

    Data |= ADCL ;
    Data |= (ADCH << 8);   

    v = Data*(0.004);      
    ftoa(v,2,strl); 
    delay_ms(500);
                   
    lcd_clear();
    lcd_puts(strl);
        
    ADCSRA &= ~(1 << ADSC);  //END = 0  
    ADCSRA |= (1 << ADIF);
    ADCSRA &= ~(1 << ADEN); 

    delay_ms(500); 
              
    }
}

/*LM35 0C=0V  100C=1V
BASE B ADC
FORMULE VOLT
V = aT  T= V/a(shib)
chap tempeture*/
