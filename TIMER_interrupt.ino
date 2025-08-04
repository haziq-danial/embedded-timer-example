#include "global.h"

int main(void) {
  volatile uint32_t delay;
  volatile uint64_t timeout;
  uint8_t toggle = 0;

  SYS_Error_Check(SYS_Init());

  timeout = SYS_TICK + 1000;

  for(;;) {
    if (SYS_TICK > timeout) {
    timeout = SYS_TICK + 1000;

      if (toggle) {
        SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
        toggle = 0;
      } else {
        SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH));
        toggle = 1;
      }
    }
  }
}