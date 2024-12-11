/* j4.c
 * Created: 11/12/2024 10:17:37 AM
 * Author: Nazanin
 */

#include <io.h>
#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdlib.h>
#include <stdio.h>

void main(void){

int x = 0;
lcd_init(16);

while (1){
    for( x ; x <= (16+7) ; x++ ){
        lcd_clear();
        lcd_gotoxy(x,1); 
        lcd_putsf("Nazanin");
        delay_ms(100);
        if (x == 9){
            lcd_gotoxy(x,1); 
            lcd_putsf("Nazanin");    
            }
        }
    x = 0;     
    }
}
/*
lcd_puts( )
lcd_putchar(' ')
*/