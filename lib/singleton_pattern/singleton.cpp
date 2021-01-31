#include "singleton_pattern/singleton_manager-internal.hpp"
#include "singleton_pattern/singleton.hpp"

namespace Is
{
    INSTANTIATE_SINGLETON(DP_API, Cpu);
    INSTANTIATE_SINGLETON(DP_API, Gpu);
}