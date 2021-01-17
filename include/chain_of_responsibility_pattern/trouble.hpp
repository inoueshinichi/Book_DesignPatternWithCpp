#ifndef CHAIN_OF_RESPONSIBILITY_TROUBLE_HPP
#define CHAIN_OF_RESPONSIBILITY_TROUBLE_HPP

#include "../common.hpp"

#include <string>
#include <sstream>

namespace Is
{
    using std::string;
    using std::stringstream;

    class DP_API Trouble
    {
        int number_;
    
    public:
        Trouble(int number) : number_(number) {}
        ~Trouble() {}

        int getNumber() { return number_; }

        string toString() 
        {
            stringstream ss;
            ss << "[Trouble " << number_ << "]";
            return  ss.str();
        }
    };
}
#endif