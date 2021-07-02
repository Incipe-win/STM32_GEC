#include "gec_gpio.h"
#include "gec_init.h"
#include "gec_time.h"
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

void led_control(int led_num, int cmd) {
  if (led_num == 0) {
    Gec_GPIO_Set_Value(GPIOF, GPIO_Pin_9, cmd);
  } else if (led_num == 1) {
    Gec_GPIO_Set_Value(GPIOF, GPIO_Pin_10, cmd);
  } else if (led_num == 2) {
    Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_13, cmd);
  } else if (led_num == 3) {
    Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_14, cmd);
  }
}

void led_init() {
  Gec_GPIO_Init(GPIOF, GPIO_Pin_9, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOF, GPIO_Pin_10, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_13, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_14, GPIO_MODE_OUT_PP);
  for (int i = 0; i < 4; ++i) {
    led_control(i, 1);
  }
}

void led_fun() {
  led_init();
  int i = 0;
  while (1) {
    i %= 4;
    led_control(i, 0);
    mdelay(500);
    led_control(i, 1);
    ++i;
  }
}
