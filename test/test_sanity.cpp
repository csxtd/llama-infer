#include <gtest/gtest.h>
#include "base/base.h"

// 最小 sanity 测试：验证构建 + 测试框架闭环是否打通。
TEST(SanityTest, GtestWorks) { EXPECT_EQ(1 + 1, 2); }

TEST(SanityTest, LinksOurLibrary) {
  EXPECT_EQ(base::add(2, 3), 5);
  EXPECT_EQ(base::add(-1, 1), 0);
}
