#ifndef INTERPERTER_PARSE_EXCEPTION_HPP
#define INTERPERTER_PARSE_EXCEPTION_HPP

#include "../common.hpp"

#include <string>
#include <exception>
#include <stdexcept>
#include <sstream>

#if defined(MSVC)
    #define __func__ __FUNCTION__
#endif

namespace Is
{
    using std::string;
    using std::stringstream;

    class DP_API ParseException : public std::exception
    {
        string full_msg_;
        string msg_;
        string file_;
        string func_;
        int line_;

    public:
        // ParseException() = default;
        // ~ParseException() = default;
        // ParseException(const ParseException&) = default;
        // ParseException& operator=(const ParseException&) = default;
        // ParseException(ParseException&&) = default;
        // ParseException& operator=(ParseException&&) = default; 

        ParseException(const string& msg, const string& file, const string& func, int line)
            : msg_(msg), file_(file), func_(func), line_(line) {
                stringstream ss;
                ss << "ParseError in " << func_ << std::endl;
                ss << file_ << ":" << line_ << std::endl;
                ss << msg_ << std::endl;
                full_msg_ = ss.str();
        }

        ~ParseException() noexcept {}

        virtual const char* what() const noexcept override
        {
            return full_msg_.c_str();
        }
    };
}
#endif