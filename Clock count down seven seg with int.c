/* Nazanin shahbaz
 *40012341054241
 *time -> 9.50 - 11.40
 *Clock count down seven seg.c*/

#include <io.h>
#include <delay.h>
#include <mega16.h>

int flag = 0;

interrupt [EXT_INT0] void myISR0() {   //second-int0
    flag = 1; 
    }                                
    
interrupt [EXT_INT1] void myISR1() {   //minute-int1
    flag = 2;   
    } 

void main(void) {

    int yekan_s = 0;
    int dahghan_s = 6;
    int yekan_m = 0;
    int dahghan_m = 6;
    
    unsigned char number[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
    
    DDRC = 0xff;    //second-7seg 
    DDRA = 0xff;    //minute-7seg  
    DDRD &= ~((1 << DDD0) | (1 << DDD1));   //input
    DDRB |= ((1 << DDB0) | (1 << DDB1) | (1 << DDB2) | (1 << DDB3)); //output
    
    GICR |= ((1 << INT0) | (1 << INT1)); 
    
    MCUCR &= ~(1 << ISC00);  //falling-edge
    MCUCR |= (1 << ISC01);  //falling-edge 
    MCUCR &= ~(1 << ISC10);  //low-level
    MCUCR &= ~(1 << ISC11);  //low-level
     
    #asm("sei")     //Set Interrupt Enable

    while (1) {  
        
        if (flag == 1){      //second      
            PORTB |= (1 << PORTB1);
            PORTC = number[yekan_s];
            delay_ms(100);
            PORTB &= ~(1 << PORTB1);

            PORTB |= (1 << PORTB0);
            PORTC = number[dahghan_s];
            delay_ms(200);
            PORTB &= ~(1 << PORTB0); 
            
            yekan_s--;  

            if (yekan_s < 0){
                yekan_s = 9;
                dahghan_s--;
            }       
            
            if (dahghan_s < 0){
                dahghan_s = 5;
                yekan_m --;
            } 
            flag = 0;
        }     
        
        else if (flag == 2){     //minute    
            PORTB |= (1 << PORTB2);
            PORTA = number[yekan_m];
            delay_ms(100);
            PORTB &= ~(1 << PORTB2);

            PORTB |= (1 << PORTB3);
            PORTA = number[dahghan_m];
            delay_ms(200);
            PORTB &= ~(1 << PORTB3); 
            
            yekan_m--;  

            if (yekan_m < 0){
                yekan_m = 9;
                dahghan_m--;
            }       
            
            if (dahghan_m < 0){
                dahghan_m = 5;
            }
            flag = 0;
        }      
        PORTB |= ((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2) | (1 << PORTB3));    
    }
}
