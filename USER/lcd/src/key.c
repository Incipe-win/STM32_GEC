#include "gec_gpio.h"
#include "gec_init.h"
#include "gec_time.h"
#include "led.h"
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

void key_init() {
  Gec_GPIO_Init(GPIOA, GPIO_Pin_0, GPIO_MODE_IN_PULLUP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_2, GPIO_MODE_IN_PULLUP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_3, GPIO_MODE_IN_PULLUP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_4, GPIO_MODE_IN_PULLUP);
}

void key_fun() {
  led_init();
  key_init();
  Gec_GPIO_Init(GPIOF, GPIO_Pin_8, GPIO_MODE_OUT_PP);
  int key1, key2, key3, key4;
  while (1) {
    for (int i = 0; i < 4; ++i) {
      led_control(i, 1);
    }
    key1 = key2 = key3 = key4 = 1;
    key1 = Gec_GPIO_Get_Value(GPIOA, GPIO_Pin_0);
    key2 = Gec_GPIO_Get_Value(GPIOE, GPIO_Pin_2);
    key3 = Gec_GPIO_Get_Value(GPIOE, GPIO_Pin_3);
    key4 = Gec_GPIO_Get_Value(GPIOE, GPIO_Pin_4);
    int sum = key1 + key2 + key3 + key4;
    if (sum <= 2) {
      Gec_GPIO_Set_Value(GPIOF, GPIO_Pin_8, 1);
    } else {
      Gec_GPIO_Set_Value(GPIOF, GPIO_Pin_8, 0);
    }
    led_control(0, key1);
    led_control(1, key2);
    led_control(2, key3);
    led_control(3, key4);
  }
}
