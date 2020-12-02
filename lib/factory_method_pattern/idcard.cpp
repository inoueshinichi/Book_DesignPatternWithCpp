#include "factory_method_pattern/idcard.hpp"

#include <iostream>

namespace Is
{
    /**
     * @brief Construct a new Id Card:: Id Card object
     * 
     * @param owner 
     */
    IdCard::IdCard(const string& owner)
        : owner_(owner)
    {
        std::cout << owner_ << "のカードを作ります." << std::endl;
    }

    /**
     * @brief 
     * 
     */
    void IdCard::use()
    {
        std::cout << owner_ << "のカードを使います." << std::endl;
    }
}