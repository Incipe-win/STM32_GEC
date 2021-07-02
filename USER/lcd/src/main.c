#include "car.h"
#include "gec_gpio.h"
#include "gec_init.h"
#include "gec_time.h"
#include "key.h"
#include "led.h"
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

int main() {
  car_init();
  int left = 0, right = 0;
  while (1) {
    left = Gec_GPIO_Get_Value(GPIOB, GPIO_Pin_6);
    right = Gec_GPIO_Get_Value(GPIOE, GPIO_Pin_5);
    if (!left && !right) {
      go_straight();
    } else if (left == 0 && right) {
      turn_right();
    } else if (left && right == 0) {
      turn_left();
    } else if (left && right) {
      car_stop();
    }
    // mdelay(10000);
    // turn_left();
    // mdelay(5000);
    // turn_right();
    // mdelay(5000);
    // car_stop();
    // mdelay(5000);
  }
  // return 0;
}
