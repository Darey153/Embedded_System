#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
  DDRC|=(1<<3);
  DDRB&=~(1<<4);
  PORTB|=(1<<3);
  DDRB&=~(1<<5);
  PORTB|=(1<<4);
  while(1){
    if(!(PINB&(1<<4))){
      for (int i=0;i<5;i++){
        PORTC |= (1<<3);
        _delay_ms(200);
        PORTC &= ~(1<<3);
        _delay_ms(200);
      }
    }
    if(!(PINB&(1<<5))){
    for (int i=0;i<5;i++){
      PORTC |= (1<<3);
      _delay_ms(600);
      PORTC &= ~(1<<3);
      _delay_ms(600);
      }
    }
  }
}
/*Using an Arduino UNO or Arduino Nano, a breadboard, an LED, and two switches, write a program that produces the functionality described below.

You may not use Arduino functions like pinMode, digitalWrite, digitalRead, etc...

If switch one is pressed, the LED will blink fast 5 times (on for 200 milliseconds and off for 200 milliseconds).
If switch two is pressed, the LED will blink slow 5 times (on for 600 milliseconds and off for 600 milliseconds).*/
