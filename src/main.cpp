/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#if __has_include(<pico/stdlib.h>)
#include <pico/stdlib.h>
#else
#include <stdlib.h>
#endif

#include <stdio.h>

#include "calc.hpp"

/**
 * @brief main function
 *
 * @return int Always 0
 */
int main() {
  uint8_t address[6];

#if __has_include(<pico/stdlib.h>)

  stdio_init_all();
  int count = 10;
  while (count > 0) {
    sleep_ms(1000);
    printf("%d\n", count);
    count--;
  }
#endif

  RandomMacAddrs::Get(address);
  // count from 1 to num
  for (int i = 0; i < 6; i++) printf("Address[%d] = %02x \n", i, address[i]);

#if __has_include(<pico/stdlib.h>)
  uint kLed = PICO_DEFAULT_LED_PIN;
  gpio_init(kLed);
  gpio_set_dir(kLed, GPIO_OUT);
  while (true) {
    gpio_put(kLed, 1);
    sleep_ms(250);
    gpio_put(kLed, 0);
    sleep_ms(250);
  }

#endif
  return 0;
}