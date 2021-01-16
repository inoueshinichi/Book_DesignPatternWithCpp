#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#if defined(_MSC_VER)
#   define __func__ __FUNCTION__
#endif

#include "common.hpp"

#include <cstdio>  // std::snprintf()
#include <cstdlib> // std::abort()
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>


namespace Is
{
    using std::string;
    using std::vector;
    using std::snprintf;
    using std::ostringstream;

#define IS_ERROR(code, msg, ...)                                                              \
    throw Exception(code, format_string(msg, ##__VA_ARGS__), __func__, __FILE__, __LINE__);   \

#define IS_CHECK(condition, code, msg, ...)                                                   \
    if (!(condition))                                                                         \
    {                                                                                         \
        IS_ERROR(code, string("Failed `" #condition "`:") + msg, ##__VA_ARGS__);              \
    }

#define IS_FORCE_ASSERT(condition, msg, ...)                                                  \
    if (!(condition))                                                                         \
    {                                                                                         \
        std::cerr << "Aborting: " << format_string(msg, ##__VA_ARGS__) << " at "              \
                  << __func__ << " in " << __FILE__ << ":" << __LINE__ << std::endl;          \
        std::abort();                                                                         \
    }


    // IS Exceptionの種類
    enum class error_code
    {
        unclassified,
        not_implemented,
        value,
        type,
        memory,
        io,
        os,
        runtime
    };


    string get_error_string(error_code code)
    {
        switch (code)
        {
#define CASE_ERROR_STRING(code_name) \
    case error_code::code_name:      \
        return #code_name;

        CASE_ERROR_STRING(unclassified);
        CASE_ERROR_STRING(not_implemented);
        CASE_ERROR_STRING(value);
        CASE_ERROR_STRING(type);
        CASE_ERROR_STRING(memory);
        CASE_ERROR_STRING(io);
        CASE_ERROR_STRING(os);
        CASE_ERROR_STRING(runtime);

        default:
            return string("");

#undef CASE_ERROR_STRING
        }
    }


    // 自作例外クラス
    class DP_API Exception : public std::exception
    {
    protected:
        error_code code_;
        string full_msg_;
        string msg_;
        string func_;
        string file_;
        int line_;

    public:
        Exception(error_code code, const string& msg, const string& func, const string& file, int line)
            : code_(code), msg_(msg), func_(func), file_(file), line_(line)
        {
            ostringstream ss;
            ss << get_error_string(code) << " error in " << func_ << std::endl;
            ss << file_ << ":" << line_ << std::endl;
            ss << msg_ << std::endl;
            full_msg_ = ss.str();
        }

        ~Exception() noexcept {} // デストラクタはデフォルトでnoexcept

        const char* what() const noexcept
        {
            return full_msg_.c_str();
        }
    };



    // string formatter
    template <typename T, typename... Args>
    string format_string(const string& format, T first, Args... rest)
    {
        // 文字列サイズを取得
        int size = snprintf(nullptr, 0, format.c_str(), first, rest...);

        if (size < 0)
        {
            std::printf("fatal error in format_string function snprintf() failed\n");
            std::abort();
        }
        vector<char> buf(size + 1); // 文字列＋ヌル文字
        snprintf(buf.data(), size + 1, format.c_str(), first, rest...);

        return string(buf.data(), buf.data() + size);
    }

    // string formatter without format
    inline string format_string(const string& format)
    {
        for (auto iter = format.begin(); iter < format.end(); ++iter)
        {
            if (*iter == '%')
            {
                if (*(iter + 1) == '%')
                {
                    ++iter;
                }
                else
                {
                    IS_ERROR(error_code::unclassified, "Invalid format_string %s", format.c_str());
                }
            }
        }
        
        return format;
    }

}
#endif