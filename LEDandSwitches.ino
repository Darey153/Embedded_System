//OLUWADAMILARE AJAYI
//ECET311 #LAB
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