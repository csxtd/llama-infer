#include <gtest/gtest.h>

// 最小 sanity 测试：验证构建 + 测试框架闭环是否打通。
TEST(SanityTest, GtestWorks) { EXPECT_EQ(1 + 1, 2); }
