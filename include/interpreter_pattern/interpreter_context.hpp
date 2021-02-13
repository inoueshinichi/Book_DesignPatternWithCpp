#ifndef INTERPRETER_CONTEXT_HPP
#define INTERPRETER_CONTEXT_HPP

#include "../common.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <deque>

namespace Is
{
    using std::string;
    using std::stringstream;
    using std::deque;

    class DP_API InterpreterContext
    {
        string current_token_;
        deque<string> text_tokens_;

        void tokenize(const string& text)
        {
            stringstream ss;
            ss << text; // o + string + stream

            string token;
            while (ss >> token) // i + string + stream
            {
                text_tokens_.push_back(std::move(token));
            }
        }

    public:
        InterpreterContext(const string& text) 
        {
            tokenize(text);
            next_token();
        }

        const string& next_token()
        {
            if (text_tokens_.size())
            {
                current_token_ = text_tokens_.front();
                text_tokens_.pop_front();
            } else {
                current_token_ = "";
            }
            return current_token_;
        }

        string current_token()
        {
            return current_token_;
        }

        void skip_token(const string& token) noexcept(false)
        {
            if (current_token_ != token) {
                string msg = "Warning: " + token + " is expected, but " + current_token_ + " is found.";
                throw ParseException(msg, __FILE__, __func__, __LINE__);
            }
            next_token();
        }

        int current_number() noexcept(false)
        {
            int number = 0;
            
            std::istringstream iss(current_token_);
            iss >> number; // 文字列 -> 数値
            if (iss.fail()) {
                string msg = string("Warning: put No integral string to integral variable; Given is ") + std::to_string(number);
                throw ParseException(msg, __FILE__, __func__, __LINE__);
            }
            return number;
        }
    };
}
#endif