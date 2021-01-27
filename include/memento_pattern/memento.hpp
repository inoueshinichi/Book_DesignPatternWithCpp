#ifndef MEMENTO_MEMENTO_HPP
#define MEMENTO_MEMENTO_HPP

#include "../common.hpp"

#include <vector>
#include <string>
#include <memory>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::vector;
    using std::string;

    class DP_API Memento
    {
        int money_;
        vector<string> fruits_;

        Memento(int money) : money_(money) {}

    public:
        ~Memento() {}

        static shared_ptr<Memento> create(int money)
        {
            return shared_ptr<Memento>(new Memento(money));
        }

        int getMoney() const
        {
            return money_;
        }

        void addFruit(const string& fruit)
        {
            fruits_.push_back(fruit);
        } 

        vector<string> getFruits() const
        {
            return fruits_;
        }
    };
}
#endif