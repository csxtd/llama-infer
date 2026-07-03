#include "base/alloc.h"

#include <gtest/gtest.h>

TEST(CPUDeviceAllocatorTest, AllocateAndRelease) {
    base::CPUDeviceAllocator alloc;

    void* ptr = alloc.allocate(32);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(alloc.device_type(), base::DeviceType::kDeviceCPU);

    alloc.release(ptr);
}
