#ifndef ITERATOR_BOOKSHELF_HPP
#define ITERATOR_BOOKSHELF_HPP

#include "aggregate.hpp"
#include "book.hpp"

#include <vector>

namespace Is
{
    using std::vector;

    class BookShelf : public Aggregate
    {
        vector<Book> books_;
        int last_;

    public:
        BookShelf(int maxsize) : last_(0) { books_.resize(maxsize); }
        Book getBookAt(int index);
        void appendBook(const Book& book);
        int getLength() { return last_; }
        Iterator iterator() override;
    }
}
#endif