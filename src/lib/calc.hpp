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

#include <algorithm>
#include <cmath>
#include <iterator>
#include <sprout/array.hpp>
#include <sprout/random.hpp>
#include <sprout/random/unique_seed.hpp>
#include <type_traits>

/**
 * @brief Test struct
 *
 */
struct RandomMacAddrs {
 private:
  static const int kAddressSize = 6;

  //
  //  SPROUT_UNIQUE_SEED は constexpr
  //  として使える、ほぼユニークかつコンパイル毎に変化する std::size_t
  //  値になる。
  //  実装は、日時とファイル名と行の文字列からハッシュ値を生成している。
  //
  static constexpr auto seed = SPROUT_UNIQUE_SEED;
  //
  //  minstd_rand0 は 線形合同法エンジンのジェネレータ。
  //
  static constexpr auto engine = sprout::random::minstd_rand0(seed);
  //
  //  uniform_smallint は 整数の一様分布。
  //  ここでは [0 .. 255] の範囲。
  //
  static constexpr auto distribution =
      sprout::random::uniform_smallint<uint8_t>(0, 255);

  // The b1:0 of the first byte is always "10".
  // This enforces the address to the private and unicast.
  static constexpr uint8_t mac_address_[kAddressSize] = {
      distribution(engine) & 0xFE | 0x02, distribution(engine)(),
      distribution(engine)()(),           distribution(engine)()()(),
      distribution(engine)()()()(),       distribution(engine)()()()()()};

 public:
  /**
   * @brief Calculate the Random MAC address at compile time
   *
   * @param param Must be positive or zero.
   * @return double square root of param
   */
  void Get(uint8_t mac_address[kAddressSize]);
};
