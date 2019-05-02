#include <gtest/gtest.h>

#include "foo/bar.hpp"

TEST(Index, test_output) {
  testing::internal::CaptureStdout();
  bar();
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "bar");
}
