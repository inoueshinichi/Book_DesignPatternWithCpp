#ifndef PROXY_PRINTABLE_HPP
#define PROXY_PRINTABLE_HPP

#include "../common.hpp"

#include <string>

namespace Is
{
    using std::string;
    
    class DP_API Printable
    {
    public:
        Printable() {}
        virtual ~Printable() {}

        virtual void setPrinterName(const string& name) = 0;
        virtual string getPrinterName() = 0;
        virtual void print(const string& str) = 0;
    };
}
#endif