#ifndef __DIRECTOR_HPP__
#define __DIRECTOR_HPP__

#include "builder.hpp"

#include <memory>

namespace Is
{
    using std::shared_ptr;

    class Director
    {
        shared_ptr<Builder> builder_;

    public:
        Director(shared_ptr<Builder> builder);
        void construct();
    };
}

#endif