#include "global.h"


int32_t TIMER0_Init(void) {
  TCCR0A = 0x02;
  TCCR0B = 0x03;
  // set reload register to 249
  OCR0A = 249;
  // clear the all flag
  TIFR0 = 0x07;
  // enable COMPA interrupt
  TIMSK0 = 0x02;
  return TIMER0_SUCCESS;
}

ISR(TIME0_COMPA_vect) {
  SYS_TICK++;
}