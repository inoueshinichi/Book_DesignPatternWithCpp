#ifndef OBSERVER_DIGIT_OBSERVER_HPP
#define OBSERVER_DIGIT_OBSERVER_HPP

#include "../common.hpp"
#include "observer.hpp"
#include "number_generator.hpp"

#include <thread>
#include <iostream>
#include <chrono>

namespace Is
{
    using std::this_thread::sleep_for;
    using std::chrono::microseconds;

    class DP_API DigitObserver : public Observer
    {
    public:
        virtual void update(shared_ptr<NumberGenerator> generator)
        {
            std::cout << "DigitObserver:" << generator->getNumber() << std::endl;
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