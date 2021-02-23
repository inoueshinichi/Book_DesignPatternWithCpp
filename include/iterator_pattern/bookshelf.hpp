#ifndef ITERATOR_BOOKSHELF_HPP
#define ITERATOR_BOOKSHELF_HPP

#include "../common.hpp"
#include "aggregate.hpp"
#include "book.hpp"

#include <vector>
#include <memory>

namespace Is
{
    using std::vector;
    using std::shared_ptr;

    // 前方宣言
    class BookShelfIterator;

    class DP_API BookShelf : public Aggregate
    {
        vector<Book> books_;

    public:
        BookShelf();
        ~BookShelf();

        Book& getBookAt(int index);

        void appendBook(Book&& book);

        inline int getLength() { return books_.size(); }

        // Java型イテレータ生成
        // shared_ptr<Iterator> iterator() override;

        // C++型イテレータ
    private:
        friend BookShelfIterator;
    public:
        using iterator = BookShelfIterator;

        BookShelf::iterator begin();
        BookShelf::iterator end();
    };
}
#endif