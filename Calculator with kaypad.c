/*
 * calculator.c
 * Created: 11/21/2024 10:44:45 PM
 * Author: Nazanin
 */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>
#include <stdio.h>

void digits (int *digit){
    int firstNumber_array[4]; 
    int secondNumber_array[4]; 
    
    int firstCount = 0;
    int secondCount = 0;

    int input = digit,i;     
    if (input >= 0 && input <= 9) {
        if (firstCount < 4) {       //4 digit for first number
            firstNumber_array[firstCount] = input; 
            firstCount++;
        } 
        else if (secondCount < 4) {       //4 digit for second number
            secondNumber_array[secondCount] = input; 
            secondCount++;
            }

        if (firstCount == 4) {       //array to number
            int firstNumber = 0;
            for (i = 0; i < 4; i++) {
                firstNumber = firstNumber * 10 + firstNumber_array[i]; 
            }
        }

        if (secondCount == 4) {       //array to number
            int secondNumber = 0;
            for (i = 0; i < 4; i++) {
                secondNumber = secondNumber * 10 + secondNumber_array[i];
            }
        }
    }


void calculate (char *sign, char *note, int *firstNumber, int *secondNumber){
    int answer = 0;
    if (equal){
        if (add){
            answer = firstNumber + secondNumber;
            lcd_putsf(answer);
        }
        else if (sub){
            answer = firstNumber - secondNumber;
            lcd_putsf(answer);
        }
        else if (multi){
            answer = firstNumber * secondNumber;
            lcd_putsf(answer);
        }
        else if (div){
            answer = firstNumber / secondNumber;
            lcd_putsf(answer);
        }        
    } 
}
       
void main(void){

int i = 0;
lcd_init(16);
bool add = false, sub = false, multi = false, div = false, equal = false;
int firstNumber_array[] = {4};
int secondNumber_array[] = {4};

DDRC &= ~((1 << DDC4) | (1 << DDC5) | (1 << DDC6) | (1 << DDC7));   //input
DDRC |= ((1 << DDC0) | (1 << DDC1) | (1 << DDC2) | (1 << DDC3));    //output
PORTC = 0xFF;   //pull-up
      
while (1) {
    for (i = 0; i < 4; i++) {
        delay_ms(150);
        PORTC = ~(1 << i);   //PORTC = 0xfe;   //0b1111 1110  //&= ~(1 << PORTC0)  
            
        if ((PINC & (1 << PINC4)) == 0) { 
            lcd_putsf("7");
            digits(&digit);
            delay_ms(500);
        } 
        else if ((PINC & (1 << PINC5)) == 0) {
            lcd_putsf("4");
            digits(&digit);
            delay_ms(500);
        } 
        else if ((PINC & (1 << PINC6)) == 0) {
            lcd_putsf("1");
            digits(&digit);
            delay_ms(500);
        } 
        else if ((PINC & (1 << PINC7)) == 0) { 
            lcd_clear(); 
            delay_ms(500);
        }

        if (i == 1) {
            if ((PINC & (1 << PINC4)) == 0) {
                lcd_putsf("8"); 
                digits(&digit);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC5)) == 0) {
                lcd_putsf("5");
                digits(&digit);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC6)) == 0) {
                lcd_putsf("2");
                digits(&digit);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC7)) == 0) {
                lcd_putsf("0");
                digits(&digit);
                delay_ms(500);
                }
            }

        if (i == 2) {
            if ((PINC & (1 << PINC4)) == 0) {
                lcd_putsf("9");
                digits(&digit);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC5)) == 0) {
                lcd_putsf("6");
                digits(&digit);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC6)) == 0) {
                lcd_putsf("3");
                digits(&digit);
                delay_ms(500);
                }
            else if ((PINC & (1 << PINC7)) == 0) {
                lcd_putsf("=");
                equal = true;
                calculate(&sign);
                delay_ms(500);
                }
            }

        if (i == 3) {
            if ((PINC & (1 << PINC4)) == 0) {
                lcd_putsf("/");
                div = true; 
                calculate(&note);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC5)) == 0) {
                lcd_putsf("*");
                multi = true;
                calculate(&note);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC6)) == 0) {
                lcd_putsf("-"); 
                sub = true;     
                calculate(&note);
                delay_ms(500);
            } 
            else if ((PINC & (1 << PINC7)) == 0) {
                lcd_putsf("+");
                add = true; 
                calculate(&note);
                delay_ms(500);
                }
            }
        }
    }
}