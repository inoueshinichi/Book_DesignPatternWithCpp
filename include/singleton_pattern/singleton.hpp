#ifndef SINGLETON_SINGLETON_HPP
#define SINGLETON_SINGLETON_HPP

#include "../common.hpp"
#include "singleton_manager-internal.hpp"

namespace Is
{
    class DP_API Cpu
    {
        friend SingletonManager;
        Cpu() {}
    public:
        ~Cpu() {}
        Cpu(const Cpu&) = delete;
        Cpu& operator=(const Cpu&) = delete;
    };

    class DP_API Gpu 
    {
        friend SingletonManager;
        Gpu() {}
    public:
        ~Gpu() {}
        Gpu(const Gpu&) = delete;
        Gpu& operator=(const Gpu&) = delete;
    };
}
#endif