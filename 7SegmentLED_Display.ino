#define F-_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define SEG_A 0
#define SEG_B 1
#define SEG_C 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 5
int main(void){
  // Set the segment pins as outputs
  DDRC |= (1 << SEG_A) | 
  (1 << SEG_B) | 
  (1 << SEG_C) | 
  (1 << SEG_D) | 
  (1 << SEG_E) |
  (1 << SEG_F);
  DDRB |= (1 << SEG_G);
  // Set the segment pins to the correct state for each digit
  const uint8_t segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1} // 9
  };
  //not binary,position of the numbers 
  // Count from 0 to 9 and repeat
  while (1){
    for (int i = 0; i < 10; i++){
      // Set the segment pins to the correct state for the current digit
      PORTC = (segments[i][0] << SEG_A) | 
      (segments[i][1] << SEG_B) |
      (segments[i][2] << SEG_C) | 
      (segments[i][3] << SEG_D) | 
      (segments[i][4] << SEG_E) |
      (segments[i][5] << SEG_F);
      PORTB = (segments[i][6] << SEG_G);
      // Delay for 1 second
      _delay_ms(1000);
    }
  }
};