#ifndef OBSERVER_RANDOM_NUMBER_GENERATOR_HPP
#define OBSERVER_RANDOM_NUMBER_GENERATOR_HPP

#include "../common.hpp"
#include "number_generator.hpp"

#include <random>

namespace Is
{
    using std::mt19937_64;
    using std::uniform_int_distribution;

    class DP_API RandomNumberGenerator : public NumberGenerator
    {
        mt19937_64 engine_;
        int number_;

    public:
        RandomNumberGenerator(int seed)
        {
            engine_.seed(seed);
        }

        virtual ~RandomNumberGenerator() {}

        virtual int getNumber() override final
        {
            return number_;
        }

        virtual void execute()
        {
            uniform_int_distribution<> dist(0, 50);
            this->number_ = dist(engine_);
            notifyObservers();
        }
    };
}
#endif