#ifndef FLYWEIGHT_BIGCHAR_HPP
#define FLYWEIGHT_BIGCHAR_HPP

#include "../common.hpp"

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <memory>

namespace Is
{
    using std::string;
    using std::unique_ptr;

    class DP_API BigChar
    {
        char char_name_;
        string dir_;
        string font_data_;
    public:
        BigChar(const char& char_name, const string& dir) : char_name_(char_name), dir_(dir)
        {
            try
            {
                // コアダンプ(Segmentaiton Fault)する. 原因わからず.
                // string fname_tmp = "big%s.txt";
                // int size = snprintf(nullptr, 0, fname_tmp.c_str(), char_name_);
                // if (size < 0)
                // {
                //     throw std::runtime_error("Failed to std::snprintf().");
                // }
                    
                // std::vector<char> buf(size + 1); // ヌル文字'\0'用に1バイトのストレージを確保
                // std::snprintf(buf.data(), size + 1, fname_tmp.c_str(), char_name_);
                // string filename(buf.data(), buf.data() + size); // ヌル文字'\0'用に1バイトは除く

                std::stringstream ss;
#if defined(WIN32)
                ss << dir_ << "\\";
#else
                ss << dir_ << "/";
#endif
                ss << "big" << char_name_ << ".txt";
                string filename = ss.str();

                // ファイルストリーム
                unique_ptr<FILE, decltype(&std::fclose)> fp(
                    std::fopen(filename.c_str(), "r"),
                    std::fclose
                );
                
                if (!fp)
                {
                    string error_msg = "Failed to open ";
                    error_msg += filename;
                    throw std::runtime_error(error_msg);
                }

                // ファイル読み込み
                char* c_line = nullptr;
                size_t len_line = 0;
                while(getline(&c_line, &len_line, fp.get()) != -1)
                {
                    font_data_ += c_line;
                    font_data_ += '\n';
                }

                std::free(c_line);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                font_data_ += char_name_;
                font_data_ += '?';
            }
        }

        ~BigChar() {}

        void print()
        {
            std::cout << font_data_ << std::endl;
        }
    };
}
#endif