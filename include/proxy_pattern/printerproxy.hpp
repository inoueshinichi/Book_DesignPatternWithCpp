#ifndef PROXY_PRINTERPROXY_HPP
#define PROXY_PRINTERPROXY_HPP

#include "../common.hpp"
#include "printable.hpp"
#include "printer.hpp"

#include <string>
#include <sstream>
#include <memory>

namespace Is
{
    using std::string;
    using std::stringstream;
    using std::unique_ptr;
    using std::make_unique;

    class DP_API PrinterProxy : public Printable
    {
        string name_;
        unique_ptr<Printer> real_;

        void realize()
        {
            if (!real_)
            {
                real_ = make_unique<Printer>(name_);
            }
        }

    public:
        PrinterProxy() {}
        virtual ~PrinterProxy() {}
        explicit PrinterProxy(const string& name) : name_(name) {}

        virtual void setPrinterName(const string& name) override final
        {
            if (real_)
            {
                real_->setPrinterName(name);
            }
            name_ = name;
        }

        virtual string getPrinterName() override final
        {
            return name_;
        }

        virtual void print(const string& str) override final
        {
            realize(); // 本人生成
            real_->print(str);
        }
    };
}
#endif