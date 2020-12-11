#ifndef ADAPTER_BANNER_HPP
#define ADAPTER_BANNER_HPP

#include <string>
#include <iostream>

namespace Is
{
    using std::string;

    class Banner
    {
        string str_;

    public:
        Banner(const string& str) : str_(str) {}
        void showWithParen() { std::cout << "(" << str_ << ")" << std::endl; }
        void showWithAster() { std::cout << "*" << str_ << "*" << std::endl; }
    };
}
#endif