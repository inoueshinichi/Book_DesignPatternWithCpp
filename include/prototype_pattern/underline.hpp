#ifndef __PROTOTYPE_UNDERLINE_HPP__
#define __PROTOTYPE_UNDERLINE_HPP__

#include "../common.hpp"
#include "product.hpp"

#include <memory>
#include <string>
#include <iostream>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    class DP_API UnderlinePen : public Product
    {
        string ulchar;

    public:
        UnderlinePen(const string& ulchar)
            : ulchar(ulchar)
        {}

        void useImpl(const string& s) override
        {
            int length = s.length();
            std::printf("\" %s \"\n", s.c_str());
            std::cout << "  ";
            for (int i = 0; i < length; ++i)
            {
                std::cout << ulchar;
            }
            std::cout << "  " << std::endl;
        }

        shared_ptr<Product> createCloneImpl() override
        {
            return std::static_pointer_cast<Product>(std::make_shared<UnderlinePen>(*this)); // コピーコンストラクタを伴う
        }
    };
}


#endif