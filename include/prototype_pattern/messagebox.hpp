#ifndef PROTOTYPE_MESSAGEBOX_HPP
#define PROTOTYPE_MESSAGEBOX_HPP

#include "../common.hpp"
#include "product.hpp"

#include <string>
#include <memory>
#include <iostream>
#include <cstdio>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    class DP_API MessageBox : public Product
    {
        string decochar;

    public:
        MessageBox(const string& decochar)
            : decochar(decochar)
        {}

        void useImpl(const string& s) override
        {
            int length = s.length() + 4;
            for (int i = 0; i < length; ++i)
            {
                std::cout << decochar;
            }
            std::cout << std::endl;
            std::printf("%s %s %s\n", decochar.c_str(), s.c_str(), decochar.c_str());
            for (int i = 0; i < length; ++i)
            {
                std::cout << decochar;
            }
            std::cout << std::endl;
        }

        shared_ptr<Product> createCloneImpl() override
        {
            return make_shared<MessageBox>(*this); // コピーコンストラクタを伴う
        }
    };
}

#endif