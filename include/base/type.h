
namespace base{

enum class DeviceType{
    kDeviceUnknown,
    kDeviceCPU,
    kDeviceCUDA
};

enum class MemcpyKind{
    kCPU2CPU,
    kCPU2CUDA,
    kCUDA2CPU,
    kCUDA2CUDA
};



}

