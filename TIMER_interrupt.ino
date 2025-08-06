#include "global.h"

int main(void) {
  volatile uint32_t delay;
  volatile uint64_t LED_timeout, sw_timeout;
  uint8_t toggle = 0;
  uint8_t sw;

  SYS_Error_Check(SYS_Init());

  LED_timeout = SYS_TICK + 1000;
  sw_timeout = SYS_TICK + 20;

  for (;;) {
    if (SYS_TICK > LED_timeout) {
      LED_timeout = SYS_TICK + 1000;

      if (toggle) {
        SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_LOW));
        toggle = 0;
      } else {
        SYS_Error_Check(GPIO_Write(LED_DEBUG_PIN, GPIO_HIGH));
        toggle = 1;
      }

    }

    // this currently doesn't work
    if (SYS_TICK > sw_timeout) {
      sw_timeout = SYS_TICK + 20;

      SYS_Error_Check(GPIO_Read(SW1_PIN, &sw));

      if(sw == GPIO_HIGH) SYS_Error_Check(GPIO_Write(LED_GREEN_PIN, GPIO_HIGH));
      else SYS_Error_Check(GPIO_Write(LED_GREEN_PIN, GPIO_LOW));

    }

  }
}
