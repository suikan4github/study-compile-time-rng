// Test cases for the calc class

#include <stdexcept>

#include "calc.hpp"
#include "gtest/gtest.h"

TEST(RandomMacAdrs, Sqrt) {
  RandomMacAddrs rma;
  uint8_t adrs[6] = {0};

  rma.Get(adrs);
  // This test is not precisely good. Because the address is random, sometimes
  // neighbor bytes can have same number. In that case, this test fails even
  // the address is random.
  EXPECT_TRUE(adrs[0] != adrs[1] && adrs[1] != adrs[2] && adrs[2] != adrs[3] &&
              adrs[3] != adrs[4] && adrs[4] != adrs[5] && adrs[5] != adrs[0]);
  // The first octet must be 0bxxxxxx10
  EXPECT_EQ(adrs[0] & 0x03, 0x02);
}
