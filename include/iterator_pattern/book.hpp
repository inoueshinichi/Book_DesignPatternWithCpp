#ifndef ITERATOR_BOOL_HPP
#define ITERATOR_BOOL_HPP

#include <string>

namespace Is
{
    using std::string;

    class Book
    {
        string name_;

    public:
        Book() {}
        ~Book() {}
        explicit Book(const string& name) : name_(name) {}

        // コピーコンストラクタ
        Book(const Book& rho) : name_(rho.name_) {}

        // コピー代入演算子
        Book& operator=(const Book& rho)
        {
            if (this == &rho)
                return *this;

            this->name_ = rho.name_;
            return *this;
        }
        
        // ムーブコンストラクタ
        Book(Book&& other) : name_(std::move(other.name_)) {}

        // ムーブ代入演算子
        Book& operator=(Book&& rho)
        {
            if (this == &rho)
                return *this;

            this->name_ = std::move(rho.name_);
            return *this;
        }
        string& getName() { return name_; }
    };
}
#endif
