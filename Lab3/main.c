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
#define typedef unsigned long uint32_t 

#define GPIO25PAD_BASE 0x40014000
#define GPIO_CTRL (GPIO25PAD_BASE+0x0cc)
#define SIO_BASE_ADDRESS 0Xd0000000
#define REG_GPIO_OE (SIO_BASE_ADDRESS+0x020) //maybe 24
#define REG_GPIO_OE_SET (SIO_BASE_ADDRESS+0x024) // maybe 14
#define REG_GPIO_OE_CLR (SIO_BASE_ADDRESS+0x028) // maybe 18
#define CONTENT_OF(adrr) (*(volatile uint32_t*)adrr)
#define LED_PIN 25

//GPIO25 ouput diabled and enable input 
*GPIO25PAD_BASE = *GPIO25PAD_BASE | (1<<6) & ~(1<<7); // Sets bit 7 to 0 and set bit 6 to 1
//GPIO25 GPIO25 functoin set to SIO
*GPIO_CTRL = 5; //

// Set the GPIO Output enable as well and that means set bit 25 of the register

uint32_t* CONTENT_OF(REG_GPIO_OE) =  (1<<LED_PIN);

while ( true ) {

//Turn LED ON
uint32_t* CONTENT_OF(REG_GPIO_OE_SET) = (1<<LED_PIN);

//Wait 
for ( uint32_t i = 0; i < 8000000; i++) {
__asm volatile ( " nop " ) ;
}

//Turn LED OFF
uint32_t* CONTENT_OF(REG_GPIO_OE_CLR) = (1<<LED_PIN);

}
}
