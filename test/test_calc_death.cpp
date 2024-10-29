
#include <stdexcept>

#include "calc.hpp"
#include "gtest/gtest.h"

// The name of the death test CASE have to  be .*DeathTest
// Read GoogleTest document
// https://github.com/google/googletest/blob/main/docs/advanced.md#death-test-naming
TEST(CalcDeathTest, SqrtWithMinusParam) {
#ifndef NDEBUG
  RandomMacAddrs rma;
  // We test only when assert() works.
  ASSERT_DEATH(rma.Get(nullptr), "");
#endif
}
