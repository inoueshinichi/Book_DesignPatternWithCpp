#include "iterator_pattern/bookshelf_iterator.hpp"
#include "iterator_pattern/book.hpp"

#include <stdexcept>
#include <sstream>

namespace Is
{
    // Java型イテレータ
    // bool BookShelfIterator::hasNext()
    // {
    //     if (index_ < bookshelf_->getLength())
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }


    // void* BookShelfIterator::next()
    // {
    //     Book* book = bookshelf_->getBookAt(index_);
    //     index_++;
    //     return book;
    // }

    // 終端イテレータを作成するデフォルトコンストラクタ
    BookShelfIterator::BookShelfIterator() : bookshelf_(nullptr), index_(-1) {}

    // イテレータを作成するコンストラクタ
    BookShelfIterator::BookShelfIterator(BookShelf* bookshelf, int index)
        : bookshelf_(bookshelf) 
    {
        if (bookshelf_)
        {
            if (index < 0 || index >= bookshelf_->books_.size())
            {
                index_ = -1; // 終端
            } else {
                index_ = index;
            }
        } else {
            index_ = -1; // 終端
        }
    }

    /*-----------------------------public----------------------------------*/

    BookShelfIterator::~BookShelfIterator() {}

    BookShelfIterator::BookShelfIterator(const BookShelfIterator& rhs)
        : bookshelf_(rhs.bookshelf_), index_(rhs.index_) {}

    BookShelfIterator& BookShelfIterator::operator=(const BookShelfIterator& rhs)
    {
        this->bookshelf_ = rhs.bookshelf_;
        this->index_ = rhs.index_;
    }

    BookShelfIterator::BookShelfIterator(BookShelfIterator&& rhs)
        : bookshelf_(rhs.bookshelf_), index_(rhs.index_) 
    {
        rhs.bookshelf_ = nullptr;
        rhs.index_ = -1;
    }

    BookShelfIterator& BookShelfIterator::operator=(BookShelfIterator&& rhs)
    {
        this->bookshelf_ = rhs.bookshelf_;
        this->index_ = rhs.index_;
        rhs.bookshelf_ = nullptr;
        rhs.index_ = -1;
    }

    // * 間接演算子
    const BookShelfIterator::reference BookShelfIterator::operator*() const
    {
        return bookshelf_->books_.at(index_);
    }

    // * 間接演算子
    BookShelfIterator::reference BookShelfIterator::operator*()
    {
        return bookshelf_->books_.at(index_);
    }

    // [] 添字演算子
    const BookShelfIterator::reference BookShelfIterator::operator[](int n) const
    {
        return bookshelf_->books_.at(n);
    }

    // [] 添字演算子
    BookShelfIterator::reference BookShelfIterator::operator[](int n)
    {
        return bookshelf_->books_.at(n);
    }

    // += 任意のインクリメント(1)
    BookShelfIterator& BookShelfIterator::operator+=(int n)
    {
        if (bookshelf_)
        {
            size_t size = bookshelf_->books_.size();
            int tmp_index = index_ + n;
            if (tmp_index >= 0)
            {
                if (tmp_index < size)
                {
                    index_ += n;
                } else if (index_ + n == size) {
                    index_ = -1;
                } else {
                    std::ostringstream oss;
                    int tmp_offset = index_ + n;
                    oss << "Out of range. Given is " << tmp_offset;
                    throw std::out_of_range(oss.str());
                }
            } else {
                std::ostringstream oss;
                int tmp_offset = index_ + n;
                oss << "Out of range. Given is " << tmp_offset;
                throw std::out_of_range(oss.str());
            }
        } else {
            // nothing
        }

        return *this;
    }

    // a+n 任意のインクリメント(2)
    BookShelfIterator& BookShelfIterator::operator+(int n)
    {
        return operator+=(n);
    }

    // -= 任意のデクリメント(1)
    BookShelfIterator& BookShelfIterator::operator-=(int n)
    {
        return operator+=(-n);
    }

    // a-n 任意のデクリメント(2)
    BookShelfIterator& BookShelfIterator::operator-(int n)
    {
        return operator-=(n);
    }

    // ++a 前置インクリメント
    BookShelfIterator& BookShelfIterator::operator++()
    {
        return operator+=(1);
    }

    // a++ 後置インクリメント
    BookShelfIterator BookShelfIterator::operator++(int)
    {
        BookShelfIterator iter = *this;  // コピーコンストラクタ
        operator++(); // 前方インクリメント
        return iter;
    }

    // --a 前置デクリメント
    BookShelfIterator& BookShelfIterator::operator--()
    {
        return operator-=(1);
    }

    // a-- 後置デクリメント
    BookShelfIterator BookShelfIterator::operator--(int)
    {
        BookShelfIterator iter = *this;  // コピーコンストラクタ
        operator--(); // 前方デクリメント
        return iter;
    }

    // a==b 等号
    bool BookShelfIterator::operator==(const BookShelfIterator& iter) const
    {
        return (this->bookshelf_ == iter.bookshelf_) && (this->index_ == iter.index_);
    }

    // a!=b 符号
    bool BookShelfIterator::operator!=(const BookShelfIterator& iter) const
    {
        return !operator==(iter);
    }

    // a>b 比較
    bool BookShelfIterator::operator>(const BookShelfIterator& iter) const
    {
        return (this->bookshelf_ == iter.bookshelf_) && (this->index_ > iter.index_);
    }

    // a>=b 比較等号
    bool BookShelfIterator::operator>=(const BookShelfIterator& iter) const
    {
        return operator==(iter) || operator>(iter);
    }

    // a<b 比較
    bool BookShelfIterator::operator<(const BookShelfIterator& iter) const
    {
        return !operator>=(iter);
    }

    // a<=b 比較等号
    bool BookShelfIterator::operator<=(const BookShelfIterator& iter) const
    {
        return !operator>(iter);
    }
}