/* seven seg.c
 * Created: 10/29/2024 10:24:23 AM
 * Author: Nazanin */

#include <io.h>
#include <delay.h>
#include <mega16.h>

void main(void){

unsigned char number[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
int count = 0;
DDRC = 0xff;    //output
DDRB &= ~((1 << DDB0) | (1 << DDB1));   //input

while (1)
    {
        if ((PINB & 0x01)== 0){
            count++; 
            PORTC = number[count];
            delay_ms(500);
        }
        if ((PINB & 0x02)== 0){
            count--;   
            PORTC = number[count];
            delay_ms(500);
        }                           
        
    }
}
