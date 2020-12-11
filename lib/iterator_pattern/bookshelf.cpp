#include "iterator_pattern/bookshelf.hpp"
#include "iterator_pattern/bookshelf_iterator.hpp"

namespace Is
{
    Book* BookShelf::getBookAt(int index)
    {
        return &(books_.at(index));
    }


    void BookShelf::appendBook(Book&& book)
    {
        books_.push_back(std::forward<Book>(book));
    }


    shared_ptr<Iterator> BookShelf::iterator()
    {
        auto iter_sp = std::make_shared<BookShelfIterator>(this);
        return std::static_pointer_cast<Iterator>(iter_sp);
    }

}