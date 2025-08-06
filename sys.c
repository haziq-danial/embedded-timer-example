#include "global.h"

int32_t SYS_ERROR_NUM;
volatile uint64_t SYS_TICK;

void SYS_Fatal_Error(int32_t err) {
  DDRB |= 0x20;
  PORTB |= 0x20;
  for(;;);
}

int32_t SYS_Init(void) {
  SYS_Error_Check(TIMER0_Init());
  SYS_TICK = 0;
  sei();

  SYS_Error_Check(GPIO_Init());
  SYS_Error_Check(GPIO_Mode(LED_DEBUG_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(LED_GREEN_PIN, GPIO_OUTPUT));
  SYS_Error_Check(GPIO_Mode(SW1_PIN, GPIO_INPUT));

  SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
  SYS_Error_Check(GPIO_Write(LED_GREEN_PIN, GPIO_LOW));



  return SYS_SUCCESS;
}