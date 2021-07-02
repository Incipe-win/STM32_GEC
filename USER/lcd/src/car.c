#include "gec_gpio.h"
#include "gec_init.h"
#include "gec_time.h"
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

void car_init() {
  Gec_GPIO_Init(GPIOG, GPIO_Pin_9, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOA, GPIO_Pin_8, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOA, GPIO_Pin_6, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_6, GPIO_MODE_OUT_PP);
  Gec_GPIO_Init(GPIOB, GPIO_Pin_6, GPIO_MODE_IN_PULLUP);
  Gec_GPIO_Init(GPIOE, GPIO_Pin_5, GPIO_MODE_IN_PULLUP);
}

void car_go() {
  Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 1);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_6, 0);
  Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_6, 1);
}

void turn_left() {
  Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_6, 0);
  Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_6, 1);
}

void turn_right() {
  Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 1);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_6, 0);
  Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_6, 0);
}

void car_stop() {
  Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_6, 0);
  Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_6, 0);
}

void go_straight(int time) {
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_6, 0);
  Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_6, 1);
  int i = 2;
  while (i--) {
    Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
    Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 1);
    mdelay(250 - time);
    Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
    Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 0);
    mdelay(time);
  }
}

void go_straight() {
  Gec_GPIO_Set_Value(GPIOG, GPIO_Pin_9, 0);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_8, 1);
  Gec_GPIO_Set_Value(GPIOA, GPIO_Pin_6, 0);
  Gec_GPIO_Set_Value(GPIOE, GPIO_Pin_6, 1);
}
