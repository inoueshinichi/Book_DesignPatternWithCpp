#ifndef ABSTRACT_FACTORY_TRAY_HPP
#define ABSTRACT_FACTORY_TRAY_HPP

#include "../common.hpp"
#include "item.hpp"

#include <memory>
#include <string>
#include <list>

namespace Is
{
    using std::shared_ptr;
    using std::string;
    using std::list;

    class DP_API Tray : public Item
    {
    protected:
        list<shared_ptr<Item>> tray_;

    public:
        explicit Tray(const string& caption) : Item(caption) {}
        virtual ~Tray() {}

        void add(shared_ptr<Item> item)
        {
            tray_.push_back(item);
        }
    };
}
#endif