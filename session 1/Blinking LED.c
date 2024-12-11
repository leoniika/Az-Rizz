/*j1.c
Created: 10/22/2024 10:49:41 AM
Author: Nazanin*/

#include <io.h>
#include <delay.h>
#include <mega16.h>
#include <stdbool.h> //Bool

void main(void){

DDRA |=((1 << DDA0) | (1 << DDA1)); //output
DDRB &= ~((1 << DDB0) | (1 << DDB1)); //input

while (1) 
    {       
        if (PINB & (1 << PORTB0)){  //Button 1 click  

            PORTA &= ~(1<<PORTA0); //portA0 -> off
              
            PORTA |= (1<<PORTA1);  //portA1 -> on        
            delay_ms(500);
            PORTA &= ~(1<<PORTA1); //portA1 -> off  
            delay_ms(500);
        }    
        else if (PINB & (1 << PORTB1)){  //Button 2 click    

            PORTA &= ~(1<<PORTA1); //portA1 -> off
             
            PORTA |= (1<<PORTA0); //portA0 -> on 
            delay_ms(500);   
            PORTA &= ~(1<<PORTA0); //portA0 -> off      
            delay_ms(500); 
        }     
        else {
            PORTA |= (1<<PORTA0); //portA0 -> on 
            PORTA &= ~(1<<PORTA1); //portA1 -> off
                    
            delay_ms(500);
                    
            PORTA &= ~(1<<PORTA0); //portA0 -> off
            PORTA |= (1<<PORTA1);  //portA1 -> on
                        
            delay_ms(500); 
        }
    }
}