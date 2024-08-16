#define F-_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

#define SEG_A PC0
#define SEG_B PC1
#define SEG_C PC2
#define SEG_D PC3
#define SEG_E PC4
#define SEG_F PC5
#define SEG_G PB5

#define ROW_0 PB3
#define ROW_1 PB2
#define ROW_2 PB1
#define ROW_3 PB0
#define COL_0 PD7
#define COL_1 PD6
#define COL_2 PD5
#define COL_3 PD4

int main(void)
{
    // Set the segment pins as outputs
    DDRC |= (1 << SEG_A) | (1 << SEG_B) | (1 << SEG_C) | (1 << SEG_D) | (1 << SEG_E) | (1 << SEG_F);
    DDRB |= (1 << SEG_G)| (1 << ROW_0) | (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3);
    DDRD &= ~((1 << COL_0) | (1 << COL_1) | (1 << COL_2) | (1 << COL_3));
    PORTB |= ((1 << ROW_0) | (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3));
    PORTD |= ((1 << COL_0) | (1 << COL_1) | (1 << COL_2) | (1 << COL_3));

    // Set the segment pins to the correct state for each digit
     while (1) {
        char key = get_key();
        switch (key) {
                case '0':
                    PORTC = 0b00111111;
                    PORTB = !0b11111111;
                    break;
                case '1':
                    PORTC = 0b00000110;
                    PORTB = !0b11111111;
                    break;
                case '2':
                    PORTC =  0b01011011;//0b01011011;
                    PORTB = 0b11111111;
                    break;
                case '3':
                    PORTC = 0b01001111;
                    PORTB = 0b11111111;
                    break;
                case '4':
                    PORTC = 0b01100110;
                    PORTB = 0b11111111;
                    break;
                case '5':
                    PORTC = 0b01101101;
                    PORTB = 0b11111111;
                    break;
                case '6':
                    PORTC = 0b01111101;
                    PORTB = 0b11111111;
                    break;
                case '7':
                    PORTC = 0b00000111;
                    PORTB = !0b11111111;
                    break;
                case '8':
                    PORTC = 0b01111111;
                    PORTB = 0b11111111;
                    break;
                case '9':
                    PORTC = 0b01101111;
                    PORTB = 0b11111111;
                    break;
                case 'A':
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
                case 'B':
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
                case 'C':
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
                case 'D':
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
                case '*':
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
                case '#':
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
                default:
                    PORTC = 0b00000000;
                    PORTB = 0b00000000;
                break;
        }
        _delay_ms(100);
    }

    return 0;
}

char get_key(void) {
    PORTB &= ~((1 << ROW_0) | (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3));
    PORTB |= (1 << ROW_0); 
    if (!(PIND & (1 << COL_0))) {
        _delay_ms(50);
        if (!(PIND & (1 << COL_0))) {
            while (!(PIND & (1 << COL_0))); 
            return '1';
        }
    }
    if (!(PIND & (1 << COL_1))) {
        _delay_ms(50); // debounce delay
        if (!(PIND & (1 << COL_1))) {
            while (!(PIND & (1 << COL_1))); 
            return '2';
        }
    }
    if (!(PIND & (1 << COL_2))) {
        _delay_ms(50); 
        if (!(PIND & (1 << COL_2))) {
            while (!(PIND & (1 << COL_2))); 
            return '3';
        }
    }
    if (!(PIND & (1 << COL_3))) {
        _delay_ms(50);
        if (!(PIND & (1 << COL_3))) {
          while (!(PIND & (1 << COL_3))); 
          return 'A';
        }
    }
    PORTB &= ~((1 << ROW_0) | (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3));
    PORTB |= (1 << ROW_1); 
    if (!(PIND & (1 << COL_0))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_0))) {
        while (!(PIND & (1 << COL_0)));
        return '4';
      }
    }
    if (!(PIND & (1 << COL_1))) {
      _delay_ms(50);
      if (!(PIND & (1 << COL_1))) {
        while (!(PIND & (1 << COL_1))); 
        return '5';
      }
    }
    if (!(PIND & (1 << COL_2))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_2))) {
        while (!(PIND & (1 << COL_2))); 
        return '6';
      }
    }
    if (!(PIND & (1 << COL_3))) {
      _delay_ms(50);
      if (!(PIND & (1 << COL_3))) {
        while (!(PIND & (1 << COL_3)));
        return 'B';
      }
    }
    PORTB &= ~((1 << ROW_0) | (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3));
    PORTB |= (1 << ROW_2); 
    if (!(PIND & (1 << COL_0))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_0))) {
        while (!(PIND & (1 << COL_0))); 
        return '7';
      }
    }
    if (!(PIND & (1 << COL_1))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_1))) {
        while (!(PIND & (1 << COL_1)));
        return '8';
      }
    }
    if (!(PIND & (1 << COL_2))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_2))) {
        while ((!PIND & (1 << COL_2)));
        return '9';
      }
    }
    if (!(PIND & (1 << COL_3))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_3))) {
        while ((!PIND & (1 << COL_3)));
        return 'C';
      }
    }
  PORTB &= ~((1 << ROW_0) | (1 << ROW_1) | (1 << ROW_2) | (1 << ROW_3));
  PORTB |= (1 << ROW_3);
  if (!(PIND & (1 << COL_0))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_0))) {
        while (!(PIND & (1 << COL_0))); 
        return '*';
      }
    }
  if (!(PIND & (1 << COL_1))) {
      _delay_ms(50);
      if (!(PIND & (1 << COL_1))) {
        while (!(PIND & (1 << COL_1)));
        return '0';
      }
    }
  if (!(PIND & (1 << COL_2))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_2))) {
        while (!(PIND & (1 << COL_2))); 
        return '#';
      }
    }
  if (!(PIND & (1 << COL_3))) {
      _delay_ms(50); 
      if (!(PIND & (1 << COL_3))) {
        while (!(PIND & (1 << COL_3)));
        return 'D';
      }
    }
    return '\0';
}
