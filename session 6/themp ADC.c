/*
 * Temperature ADC.c
 * Created: 12/2/2024 12:33:41 AM
 * Author: Nazanin
 */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

void main(void){

unsigned char strl [5];

//MUX = 0000
ADMUX &= ~(1 << MUX0);
ADMUX &= ~(1 << MUX1);
ADMUX &= ~(1 << MUX2);
ADMUX &= ~(1 << MUX3);
ADMUX &= ~(1 << MUX4);

ADMUX |= (1 << REFS0);
ADMUX &= ~(1 << REFS1);
ADMUX &= ~(1 << ADLAR);

ADCSRA &= ~(1 << ADSC);
ADCSRA &= ~(1 << ADATE); 
ADCSRA &= ~(1 << ADIF);
ADCSRA &= ~(1 << ADIE);
ADCSRA &= ~(1 << ADPS0);
ADCSRA |= ((1 << ADPS1) | (1 << ADPS2)); //0 1 1
ADCSRA |= (1 << ADEN);

lcd_init(16); 

while (1)
    { 
    unsigned int Temperature = 0;   
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

    Temperature |= ADCL ;
    Temperature |= (ADCH << 8);   


    //0C=0V  100C=1V 
    //a = (1-0.5)/(100-50)= 0.01
    v = Temperature*(0.01); 
         
    ftoa(v,2,strl); 
    delay_ms(500);
                   
    lcd_clear();
    lcd_puts(strl);    
    lcd_putsf(" C*");
        
    ADCSRA &= ~(1 << ADSC);  //END = 0  
    ADCSRA |= (1 << ADIF);
    ADCSRA &= ~(1 << ADEN); 

    delay_ms(500); 
              
    }
}

/*0C=0V  100C=1V
FORMULE VOLT
V = aT  T= V/a(shib)
chap tempeture*/

