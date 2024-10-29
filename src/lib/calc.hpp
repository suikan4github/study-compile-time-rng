/**
 * @file calc.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdint.h>

#include <cmath>
/**
 * @brief Test struct
 *
 */
struct RandomMacAddrs {
 private:
  static const int kAddressSize = 6;
  const uint8_t mac_address_[kAddressSize] = {0};

 public:
  /**
   * @brief Calculate the Random MAC address at compile time
   *
   * @param param Must be positive or zero.
   * @return double square root of param
   */
  void Get(uint8_t mac_address[kAddressSize]);
};
