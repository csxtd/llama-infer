#include "base/alloc.h"
#include <cstdlib>
#include <cstring>
namespace base{

CPUDeviceAllocator::CPUDeviceAllocator()
    :DeviceAllocator(DeviceType::kDeviceCPU){}
    
    void* CPUDeviceAllocator::allocate(std::size_t byte_size) const{
        if (byte_size == 0 ){
            return nullptr;
        }
        return std::malloc(byte_size);

        
    }
    
    void CPUDeviceAllocator::release(void* ptr) const{
        if (ptr != nullptr){
            std::free(ptr);
        }
        
    }
    
    void CPUDeviceAllocator::memcpy(
        const void* src_ptr,
        void* dst_ptr,
        std::size_t byte_size,
        MemcpyKind memcpy_kind
        //void* stream = nullptr,
        //bool need_sync = false

    ) const{
        if (byte_size == 0) return;
        if (!src_ptr || !dst_ptr) return ;
        if (memcpy_kind == MemcpyKind::kCPU2CPU){
            std::memcmp(src_ptr, dst_ptr, byte_size);
        }

    }

}
