Part 1
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  TCCR0A |=(1<<WGM01)|(1<<WGM00);
  TCCR0B |= (1<<CS01)|(1<<CS00);
  TCCR0A |= (1<<COM0A1)|(1<<COM0A0);
  DDRD |= (1<<PD6);
  OCR0A=0;
  OCR0B=0;
  
  while(1)
  {
    OCR0A=OCR0A+1;
    OCR0B=OCR0B+1;
    
    _delay_ms(10);
  }
}
Part 2
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  TCCR0A |=(1<<WGM01)|(1<<WGM00)|(1<<COM0A1)|(1<<COM0A0);
  TCCR0B |= (1<<CS01)|(1<<CS00);
  TCCR0A |= (1<<COM0A1)|(1<<COM0A0);

  TCCR1A |=(1<<WGM01)|(1<<WGM00)|(1<<COM0A1)|(1<<COM0A0);
  TCCR1B |= (1<<CS01)|(1<<CS00);
  TCCR1A |= (1<<COM0A1)|(1<<COM0A0);

  TCCR2A |=(1<<WGM01)|(1<<WGM00)|(1<<COM0A1)|(1<<COM0A0);
  TCCR2B |= (1<<CS01)|(1<<CS00);
  TCCR2A |= (1<<COM0A1)|(1<<COM0A0);

  DDRD |= (1<<PD6);
  DDRB |= (1<<PB3)|(1<<PB1);
  OCR0A=0;
  OCR1A=0;
  OCR2A=0;
  

  while(1)
  {
    OCR0A=OCR0A+1;
    OCR2A=OCR2A+2;
    OCR1A=OCR1A+3;
    _delay_ms(10);
  }
}