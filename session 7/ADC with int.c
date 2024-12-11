/*
 * j7.c
 * Created: 12/10/2024 10:17:46 AM
 * Author: Nazanin
 */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>

unsigned int Temperature = 0;
float v;
unsigned char strl [5];

interrupt [ADC_INT] void myADCISR(){
    Temperature |= ADCL ;
    Temperature |= (ADCH << 8);
    
    /*0C=0V  100C=1V 
      a = (1-0.5)/(100-50)= 0.01*/
    v = (Temperature*(0.5))-1;  
    
    ftoa(v,2,strl);                
    lcd_clear();
    lcd_puts(strl);    
    lcd_putsf(" C*");    
}

interrupt [EXT_INT0] void myISR0(){}

void main(void){

//MUX = 0000
ADMUX &= ~(1 << MUX0);
ADMUX &= ~(1 << MUX1);
ADMUX &= ~(1 << MUX2);
ADMUX &= ~(1 << MUX3);
ADMUX &= ~(1 << MUX4);

ADMUX |= (1 << REFS0);
ADMUX &= ~(1 << REFS1);
ADMUX &= ~(1 << ADLAR);


ADCSRA |= (1 << ADATE); //Auto Triggering = 1 
ADCSRA |= (1 << ADIE); //Interrupt Enable = 1
GICR |= (1 << INT0); //General Interrupt Control Register
MCUCR |= (1 << ISC00); 
MCUCR |= (1 << ISC01);

ADCSRA &= ~(1 << ADPS0);
ADCSRA |= ((1 << ADPS1) | (1 << ADPS2)); //0 1 1

ADCSRA |= (1 << ADEN);
ADCSRA &= ~(1 << ADSC);

SFIOR &= ~(1 << ADTS0);    
SFIOR |= (1 << ADTS1);
SFIOR &= ~(1 << ADTS2);

lcd_init(16); 
#asm("sei")

while (1)
    { 

   /* ADMUX &= ~(1 << MUX0);
    ADMUX &= ~(1 << MUX1);
    ADMUX &= ~(1 << MUX2);
    ADMUX &= ~(1 << MUX3);

    ADCSRA |= (1 << ADEN);
    delay_us(10);

    ADCSRA |= (1 << ADSC);  //start = 1   */      

  //  ADCSRA &= ~(1 << ADEN); 

   // delay_ms(500); 
              
    }
}