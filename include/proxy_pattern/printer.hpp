#ifndef PROXY_PRINTER_HPP
#define PROXY_PRINTER_HPP

#include "../common.hpp"
#include "printable.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <chrono>

namespace Is
{
    using std::string;
    using std::stringstream;

    class DP_API Printer : public Printable
    {
        string name_;

        // 重い作業
        void heavyJob(const string& msg)
        {
            std::cout << msg;
            for (int i = 0; i < 5; ++i)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                std::cout << ".";
            }
            std::cout << "完了" << std::endl;
        }

    public:
        Printer()
        {
            heavyJob("Printerのインスタンスを生成中.");
        }

        explicit Printer(const string& name) : name_(name)
        {
            stringstream ss;
            ss << "Printerのインスタンス(" << name << ")を生成中";
            heavyJob(ss.str());
        }

        virtual ~Printer() {}

        void setPrinterName(const string& name)
        {
            name_ = name;
        }

        string getPrinterName()
        {
            return name_;
        }

        void print(const string& str)
        {
            std::cout << "=== " << name_ << " ===" << std::endl;
            std::cout << str << std::endl;
        }
    };
}
#endif