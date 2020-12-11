#ifndef ITERATOR_BOOKSHELF_HPP
#define ITERATOR_BOOKSHELF_HPP

#include "aggregate.hpp"
#include "book.hpp"

#include <vector>
#include <memory>

namespace Is
{
    using std::vector;
    using std::shared_ptr;

    class BookShelf : public Aggregate
    {
        vector<Book> books_;

    public:
        BookShelf(int maxsize) {}
        Book* getBookAt(int index);
        void appendBook(Book&& book);
        int getLength() { return books_.size(); }
        shared_ptr<Iterator> iterator() override;
    };
}
#endif