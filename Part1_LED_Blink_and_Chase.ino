#define F-_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
//main function
int main(void)
{
 DDRB |= (1 << 5);
 while (1)
 {
 for (int i = 0; i < 5; i++)
 {
 PORTB |= (1 << 5);
 _delay_ms(500);
 PORTB &= ~(1 << 5);
 _delay_ms(500);
 }
 for (int i = 0; i < 5; i++)
 {
 PORTB |= (1 << 5);
 _delay_ms(1000);
 PORTB &= ~(1 << 5);
 _delay_ms(1000);
 }
 }
 return 0;
}