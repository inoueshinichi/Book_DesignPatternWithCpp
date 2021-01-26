#ifndef OBSERVER_NUMBER_GENERATOR_HPP
#define OBSERVER_NUMBER_GENERATOR_HPP

#include "../common.hpp"
#include "observer.hpp"

#include <memory>
#include <vector>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::vector;
    using std::enable_shared_from_this;

    class DP_API NumberGenerator : public enable_shared_from_this<NumberGenerator>
    {
        vector<shared_ptr<Observer>> observers;

    protected:
        NumberGenerator() {}
    
    public:
        virtual ~NumberGenerator() {}
        virtual int getNumber() = 0;
        virtual void execute() = 0;

        void addObserver(shared_ptr<Observer> observer)
        {
            observers.push_back(observer);
        }

        void deleteObserver(shared_ptr<Observer> observer)
        {
            std::erase(observers, observer);
        }

        void notifyObservers()
        {
            for (auto& observer : observers)
            {
                observer->update(shared_from_this());
            }
        }
    };
}
#endif