#include "iterator_pattern/book.hpp"

namespace Is
{
    Book::Book() {}

    Book::~Book() {}

    Book::Book(const string& name) : name_(name) {}

    Book::Book(const Book& rhs) : name_(rho.name_) {}

    Book& Book::operator=(const Book& rhs)
    {
        if (this == &rhs)
            return *this;

        this->name_ = rhs.name_; // stringのコピー代入演算子
        return *this;
    }

    Book& Book::operator=(Book&& rhs)
    {
        if (this == &rhs)
            return *this;

        this->name_ = std::move(rhs.name_); // stringのムーブ代入演算子
        return *this;
    }
}