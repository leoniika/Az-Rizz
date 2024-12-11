/* Nazanin
 *99 to 00 seven seg.c*/

#include <io.h>
#include <delay.h>
#include <mega16.h>

void main(void) {

    int yekan = 9;
    int dahghan = 9;
    unsigned char number[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
    int flag = 0;
    
    DDRC = 0xff;    //output    
    DDRA |= ((1 << DDA0) | (1 << DDA1));    //output
    DDRB &= ~((1 << DDB0) | (1 << DDB1) | (1 << DDB2)); //input

    while (1) {  
    
        if ((PINB & 0x01) == 0) {   //start
            flag = 1;
            delay_ms(200);
        }    

        else if ((PINB & 0x02) == 0) {   //pause
            flag = 0;
            PORTA &= ~(1 << PORTA1);    //off
            delay_ms(50);  

            PORTA &= ~(1 << PORTA0);
        }

        else if ((PINB & 0x04) == 0) {   //stop 
            flag = 0;
            PORTA |= (1 << PORTA0); //on
            PORTC = number[yekan];
            delay_ms(50);  

            PORTA |= (1 << PORTA1); //on
            PORTC = number[dahghan]; 
            
            yekan = 9;
            dahghan = 9;
        }
        
        if (flag){      //flag = 1
            PORTC = number[yekan];   
            PORTA |= (1 << PORTA1);    //on
            delay_ms(50);
            PORTA &= ~(1 << PORTA1);    //off

            PORTC = number[dahghan]; 
            PORTA |= (1 << PORTA0);    //on
            delay_ms(100);
            PORTA &= ~(1 << PORTA0);    //off 
            
            yekan--; 
            
            delay_ms(200); 

            if (yekan < 0){
                yekan = 9;
                dahghan--;
            }
            if (dahghan < 0){
                dahghan = 9;
            }
        }
    }
}
