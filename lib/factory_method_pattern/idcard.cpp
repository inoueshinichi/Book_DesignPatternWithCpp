#include "factory_method_pattern/idcard.hpp"

#include <iostream>

namespace Is
{
    IdCard::IdCard(const string& owner)
        : owner_(owner)
    {
        std::cout << owner_ << "のカードを作ります." << std::endl;
    }

    void IdCard::use()
    {
        std::cout << owner_ << "のカードを使います." << std::endl;
    }
}
