#define F-_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define LED1 PB0
#define LED2 PB1
#define LED3 PB2
#define LED4 PB3
int main(void)
{
 DDRB |= (1 << LED1) | (1 << LED2) | (1 << LED3) | (1 << LED4);
 while (1)
 {
 PORTB = (1 << LED1);
 _delay_ms(1000);
 PORTB = (1 << LED2);
 _delay_ms(1000);
 PORTB = (1 << LED3);
 _delay_ms(1000);
 PORTB = (1 << LED4);
 _delay_ms(1000);
 }
 return 0;
}