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
#if __has_include(<hardware/stdlib.h>)
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
  RandomMacAddrs rma;
  uint8_t address[6];

#if __has_include(<hardware/stdlib.h>)
  stdio_init_all();
#endif

  rma.Get(address);
  // count from 1 to num
  for (int i = 0; i < 6; i++) printf("Address[%d] = %02x \n", i, address[i]);

  return 0;
}