/**
 * @file calc.hpp
 * @author Seiichi Horie
 * @brief
 * @version 0.1
 * @date 2024-Oct-29
 *
 * @copyright Copyright (c) Seiichi Horie 2024
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
 * @brief Obtain a random private MAC address at compile time.
 *
 * @details
 * This class obtain a random private MAC address at compile time.
 * It is important to obtain in the compile time, especially for the
 * bare metal system. Otherwise we have to ensure some random number
 * hardware on the target.
 *
 * The random address is calculated by the Sprout library by
 * Bolero Murakami.
 *
 *   https://github.com/bolero-MURAKAMI/Sprout
 *
 *
 */
struct RandomMacAddrs {
 private:
  static const int kAddressSize = 6;

  //
  //  SPROUT_UNIQUE_SEED は constexpr is a has value from
  // - Date and Time.
  // - File name.
  // - String of this line.
  static constexpr auto seed = SPROUT_UNIQUE_SEED;
  //
  //  minstd_rand0 is a Linear congruential generator.
  //
  static constexpr auto engine = sprout::random::minstd_rand0(seed);
  //
  //  The uniform_smallint is a range of the Uniform distribution.
  //  We set it as the range of a byte number.
  //
  static constexpr auto distribution =
      sprout::random::uniform_smallint<uint8_t>(0, 255);

  /**
   * @brief A random address.
   * @details
   * The distribution(engine) returns always same number inside a
   * compile. To obtain the next random value, we need to add "()".
   *
   * The b1:0 of the first byte is always "10". This enforces the address to the
   * private and unicast.
   */
  static constexpr uint8_t mac_address_[kAddressSize] = {
      distribution(engine) & 0xFE | 0x02, distribution(engine)(),
      distribution(engine)()(),           distribution(engine)()()(),
      distribution(engine)()()()(),       distribution(engine)()()()()()};

 public:
  /**
   * @brief Calculate the Random MAC address at compile time
   *
   * @param mac_address 6bytes buffer to receive the random address.
   * This address is private and unicast.
   */
  static void Get(uint8_t mac_address[kAddressSize]);
};
