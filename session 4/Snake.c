/* snake.c
 * Created: 11/15/2024 7:42:14 PM
 * Author: Nazanin
 */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h> 

void main(void) {

lcd_init(20);
DDRC &= ~((1 << DDC0) | (1 << DDC1) | (1 << DDC2)| (1 << DDC3));//input   
    
int foodX = 0;
int foodY = 0;  

char snake = 'O';   
char food = '*';             
    
lcd_gotoxy(snakeX[0], snakeY[0]);
lcd_putchar(snake);

lcd_gotoxy(foodX, foodY);
lcd_putchar(food);

int LCDx = 4;
int LCDy = 20;  
int snake_max = 20;     //max body

int snakeX[snake_max] = {0};    //current body
int snakeY[snake_max] = {0};
int length = 1;     //head-start

while (1) {

    lcd_gotoxy(snakeX[length - 1], snakeY[length - 1]);
    lcd_putchar(' ');     //erase prev state
    
    for (int i = length - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
        }

    if ((PINC & (1 << PINC0)) == 0) {
        if (snakeY[0] > 0) snakeY[0]--; // UP
        } 
    else if ((PINC & (1 << PINC1)) == 0) {
        if (snakeY[0] < LCD_HEIGHT - 1) snakeY[0]++; // DOWN
    } 
    else if ((PINC & (1 << PINC2)) == 0) {
        if (snakeX[0] > 0) snakeX[0]--; // LEFT
    } 
    else if ((PINC & (1 << PINC3)) == 0) {
        if (snakeX[0] < LCD_WIDTH - 1) snakeX[0]++; // RIGHT
    }
  
    lcd_gotoxy(snakeX[0], snakeY[0]);  //new state
    lcd_putchar(snake);
    
    for (int j = 1; j < length; j++) {
        lcd_gotoxy(snakeX[j], snakeY[j]);
        lcd_putchar(snake);       //snake body
        }
        
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
            if (length < snake_max) {
                length++;      //snake eats food
                }     
        }

    foodX = rand() % LCDx;
    foodY = rand() % LCDy;

    lcd_gotoxy(foodX, foodY);
    lcd_putchar(food);    //new food

    delay_ms(200); 
    }
}