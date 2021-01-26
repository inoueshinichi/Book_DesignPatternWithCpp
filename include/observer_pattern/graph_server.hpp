#ifndef OBSERVER_GRAPH_OBSERVER_HPP
#define OBSERVER_GRAPH_OBSERVER_HPP

#include "../common.hpp"
#include "observer.hpp"
#include "number_generator.hpp"

#include <memory>
#include <cstdio>
#include <thread>
#include <chrono>
#include <iostream>

namespace Is
{
    using std::shared_ptr;
    using std::printf;
    using std::this_thread::sleep_for;
    using std::chrono::microseconds;

    class DP_API GraphObserver : public Observer
    {
    public:
        virtual void update(shared_ptr<NumberGenerator> generator) override final
        {
            printf("GraphObserver:");

#if defined(WIN32)
#   define LR "\r\n"
#else
#   define LR "\n"
#endif
            for (int count = generator->getNumber(), i = 0; i < count; ++i)
                printf("*");

            printf(LR);
#undef LR
            try
            {
                sleep_for(microseconds(100));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    };
}
#endif