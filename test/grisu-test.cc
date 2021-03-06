// Formatting library for C++ - Grisu tests
//
// Copyright (c) 2012 - present, Victor Zverovich
// All rights reserved.
//
// For the license information refer to format.h.

#define FMT_USE_GRISU std::numeric_limits<double>::is_iec559
#include "fmt/format.h"
#include "gtest.h"

bool reported_skipped;

#undef TEST
#define TEST(test_fixture, test_name)        \
  void test_fixture##test_name();            \
  GTEST_TEST(test_fixture, test_name) {      \
    if (FMT_USE_GRISU) {                     \
      test_fixture##test_name();             \
    } else if (!reported_skipped) {          \
      reported_skipped = true;               \
      fmt::print("Skipping Grisu tests.\n"); \
    }                                        \
  }                                          \
  void test_fixture##test_name()

TEST(GrisuTest, NaN) {
  EXPECT_EQ("nan", fmt::format("{}", std::numeric_limits<double>::quiet_NaN()));
}
