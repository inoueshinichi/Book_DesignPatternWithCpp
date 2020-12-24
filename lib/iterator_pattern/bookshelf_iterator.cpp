#include "iterator_pattern/bookshelf_iterator.hpp"
#include "iterator_pattern/book.hpp"


namespace Is
{
    bool BookShelfIterator::hasNext()
    {
        if (index_ < bookshelf_->getLength())
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    void* BookShelfIterator::next()
    {
        Book* book = bookshelf_->getBookAt(index_);
        index_++;
        return book;
    }
}