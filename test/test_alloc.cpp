#include "base/alloc.h"

#include <gtest/gtest.h>
namespace base{

TEST(CPUDeviceAllocatorTest, AllocateAndRelease) {
    CPUDeviceAllocator alloc;

    void* ptr = alloc.allocate(32);
    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(alloc.device_type(), base::DeviceType::kDeviceCPU);

    alloc.release(ptr);
}

TEST(test_alloc, cpu_allocate_zero){

    CPUDeviceAllocator alloc;
    void* ptr = alloc.allocate(0);
    EXPECT_EQ(ptr, nullptr);
}


TEST(test_alloc, device_type) {
    CPUDeviceAllocator alloc;

    EXPECT_EQ(alloc.device_type(), DeviceType::kDeviceCPU);
}

TEST(test_alloc, cpu_memcpy) {
    CPUDeviceAllocator alloc;

    int src[4] = {1, 2, 3, 4};
    int dst[4] = {0, 0, 0, 0};

    alloc.memcpy(src, dst, sizeof(src), MemcpyKind::kCPU2CPU);

    EXPECT_EQ(dst[0], 1);
    EXPECT_EQ(dst[1], 2);
    EXPECT_EQ(dst[2], 3);
    EXPECT_EQ(dst[3], 4);
}

TEST(test_alloc, cpu_memcpy_zero_byte) {
    CPUDeviceAllocator alloc;

    int src[4] = {1, 2, 3, 4};
    int dst[4] = {0, 0, 0, 0};

    alloc.memcpy(src, dst, 0, MemcpyKind::kCPU2CPU);

    EXPECT_EQ(dst[0], 0);
    EXPECT_EQ(dst[1], 0);
    EXPECT_EQ(dst[2], 0);
    EXPECT_EQ(dst[3], 0);
}

TEST(test_alloc, cpu_memcpy_nullptr) {
    CPUDeviceAllocator alloc;

    int dst[4] = {0, 0, 0, 0};

    alloc.memcpy(nullptr, dst, sizeof(dst), MemcpyKind::kCPU2CPU);

    EXPECT_EQ(dst[0], 0);
    EXPECT_EQ(dst[1], 0);
    EXPECT_EQ(dst[2], 0);
    EXPECT_EQ(dst[3], 0);
}




}
