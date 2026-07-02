#pragma once

#include "base/type.h"
#include <cstddef>
namespace base{

class DeviceAllocator{

public:
    explicit DeviceAllocator(DeviceType device_type)
        : device_type_(device_type){}

    virtual ~DeviceAllocator() = default;

    DeviceType device_type() const{
        return device_type_;
    }

    virtual void* allocate(std::size_t byte_size) const = 0;

    virtual void release(void* ptr) const = 0;

    virtual void memcpy(
        const void* src_ptr,
        void* dst_ptr,
        std::size_t byte_size,
        MemcpyKind memcpy_kind = MemcpyKind::kCPU2CPU
        //void* stream = nullptr,
        //bool need_sync = false

    ) const = 0;

private:
    DeviceType device_type_ = DeviceType::kDeviceUnknown;

};

class CPUDeviceAllocator : public DeviceAllocator{
public:
    CPUDeviceAllocator();
    void* allocate(std::size_t byte_size) const override;
    void release(void* ptr) const override;
    void memcpy(
        const void* src_ptr,
        void* dst_ptr,
        std::size_t byte_size,
        MemcpyKind memcpy_kind
        //void* stream = nullptr,
        //bool need_sync = false

    ) const override;

};

} // namespace base
