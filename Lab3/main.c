/**************************************************************
 * main.c
 * rev 1.0 17-Aug-2021 khan
 * Lab3
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>



int main ( void ) {
// TODO − Initialise components and variables
//enable the pads
typedef unsigned long uint32_t ;

uint32_t* GPIO25PAD_BASE = 0x40014000
uint32_t* GPIO_CTRL = (GPIO25PAD_BASE+0x0cc)
uint32_t* SIO_BASE = 0Xd0000000
uint32_t* REG_GPIO_OE = (SIO_BASE+0x020)
uint32_t* REG_GPIO_OE_SET = (SIO_BASE+0x024)
uint32_t* REG_GPIO_OE_CLR = (SIO_BASE+0x028)
uint32_t* CONTENT_OF(REG_GPIO_OE_SET) = (*(volatile uint32_t*)REG_GPIO_OE_SET)
uint32_t* CONTENT_OF(REG_GPIO_OE_CLR) = (*(volatile uint32_t*)REG_GPIO_OE_CLR)
uint32_t LED_PIN = 25

//GPIO25 ouput diabled and enable input 
*GPIO25PAD_BASE = *GPIO25PAD_BASE | (1<<6) & ~(1<<7); // Sets bit 7 to 0 and set bit 6 to 1
//GPIO25 GPIO25 functoin set to 0x1f
*GPIO_CTRL = 5; //

while ( true ) {

//Turn LED ON
uint32_t* CONTENT_OF(REG_GPIO_OE_SET) =  LED_PIN;

//Wait 
for ( uint32_t i = 0; i < 8000000; i++) {
__asm volatile ( " nop " ) ;
}

//Turn LED OFF
uint32_t* CONTENT_OF(REG_GPIO_OE_CLR) =  LED_PIN;

}
}