/*
 * j5.c
 * Created: 11/19/2024 10:34:54 AM
 * Author: Nazanin
 */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>
#include <stdio.h>

void main(void){

int i = 0;
lcd_init(16);

DDRC &= ~((1 << DDC4) | (1 << DDC5) | (1 << DDC6) | (1 << DDC7));   //input
DDRC |= ((1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3));    //output
PORTC = 0xFF;   //pull-up
      
while (1) {
    for (i = 0; i < 4; i++) {
        delay_ms(150);
        PORTC = ~(1 << i); //PORTC = 0xfe;  //0b1111 1110  //&= ~(1 << PORTC0)  
            
        if ((PINC & (1 << PINC4)) == 0) { 
            lcd_putsf("7");
            delay_ms(500);
        } 
        else if ((PINC & (1 << PINC5)) == 0) {
            lcd_putsf("4");
            delay_ms(500);
        } 
        else if ((PINC & (1 << PINC6)) == 0) {
            lcd_putsf("1");
            delay_ms(500);
        } 
        else if ((PINC & (1 << PINC7)) == 0) { 
            lcd_clear();
            delay_ms(500);
        }

        if (i == 1) {
            if ((PINC & (1 << PINC4)) == 0) {
                lcd_putsf("8");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC5)) == 0) {
                lcd_putsf("5");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC6)) == 0) {
                lcd_putsf("2");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC7)) == 0) {
                lcd_putsf("0");
                delay_ms(500);
                }
            }

        if (i == 2) {
            if ((PINC & (1 << PINC4)) == 0) {
                lcd_putsf("9");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC5)) == 0) {
                lcd_putsf("6");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC6)) == 0) {
                lcd_putsf("3");
                delay_ms(500);
                }
            else if ((PINC & (1 << PINC7)) == 0) {
                lcd_putsf("=");
                delay_ms(500);
                }
            }

        if (i == 3) {
            if ((PINC & (1 << PINC4)) == 0) {
                lcd_putsf("/");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC5)) == 0) {
                lcd_putsf("*");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC6)) == 0) {
                lcd_putsf("-");
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC7)) == 0) {
                lcd_putsf("+");
                delay_ms(500);
                }
            }
        }
    }
}

/* if(i==0){ 
           
            PORTC = 0xfe;   //0b1111 1110  //&= ~(1 << PORTC0)  
            
            if ((PINC &(1 << PINC4)) == 0){
            lcd_putsf("7"); 
            delay_ms(500);
                }
            else if ((PINC &(1 << PINC5)) == 0){
            lcd_putsf("4");
            delay_ms(500);    
                }
            else if ((PINC &(1 << PINC6)) == 0){
            lcd_putsf("1");
            delay_ms(500);    
                }
        } 
        
        else if(i == 1){
            PORTC &= ~(1 << PORTC1);   //0b1111 1110  //&= ~(1 << PORTC0)  
            
            if ((PINC &(1 << PINC4)) == 0){
            lcd_putsf("8"); 
            delay_ms(500);
                }
            else if ((PINC &(1 << PINC5)) == 0){
            lcd_putsf("5");
            delay_ms(500);    
                }
            else if ((PINC &(1 << PINC6)) == 0){
            lcd_putsf("2");
            delay_ms(500);    
                } 
            else if ((PINC &(1 << PINC7)) == 0){
            lcd_putsf("0");
            delay_ms(500);    
                }
        }

        else if(i == 2){  
            PORTC &= ~(1 << PORTC2);
            
            if ((PINC &(1 << PINC4)) == 0){
            lcd_putsf("9"); 
            delay_ms(500);
                }
            else if ((PINC &(1 << PINC5)) == 0){
            lcd_putsf("6");
            delay_ms(500);    
                }
            else if ((PINC &(1 << PINC6)) == 0){
            lcd_putsf("3");
            delay_ms(500);    
                }     
        }
        else if(i == 3){
            PORTC &= ~(1 << PORTC3);
            
            if ((PINC &(1 << PINC4)) == 0){
            lcd_putsf("/"); 
            delay_ms(500);
                }
            else if ((PINC &(1 << PINC5)) == 0){
            lcd_putsf("*");
            delay_ms(500);    
                }
            else if ((PINC &(1 << PINC6)) == 0){
            lcd_putsf("-");
            delay_ms(500);    
                }
            else if ((PINC &(1 << PINC7)) == 0){
            lcd_putsf("+");
            delay_ms(500);    
                }
        }
    }  
    i == 0;     
}
}
 */