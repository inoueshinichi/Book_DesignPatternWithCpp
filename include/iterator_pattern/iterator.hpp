#ifndef ITERATOR_ITERATOR_HPP
#define ITERATOR_ITERATOR_HPP

#include "../common.hpp"

namespace Is
{
    class DP_API Iterator
    {
    public:
        virtual bool hasNext() = 0;
        virtual void* next() = 0;
    };
}
#endif
