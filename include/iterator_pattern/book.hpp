#ifndef ITERATOR_BOOL_HPP
#define ITERATOR_BOOL_HPP

#include "../common.hpp"

#include <string>

namespace Is
{
    using std::string;

    class DP_API Book
    {
        string name_;

    public:
        Book();
        ~Book();
        explicit Book(const string& name);

        // コピーコンストラクタ
        Book(const Book& rhs);

        // コピー代入演算子
        Book& operator=(const Book& rhs);
        
        // ムーブコンストラクタ
        Book(Book&& other) : name_(std::move(other.name_)) {}

        // ムーブ代入演算子
        Book& operator=(Book&& rhs);

        inline string& getName() { return name_; }
    };
}
#endif
