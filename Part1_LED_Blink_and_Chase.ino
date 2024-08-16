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
/*Part 1: Using an Arduino UNO or Arduino Nano, a breadboard, and an LED, write a program in that will do the following:

You may not use Arduino functions like pinMode, digitalWrite, digitalRead, etc...

Blink the LED 5 times (on for 500 milliseconds and off for 500 milliseconds).
Blink the LED 5 times (on for 1 second and off for 1 second).
Repeat forever.*/
