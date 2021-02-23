#ifndef ITERATOR_BOOKSHELF_ITERATOR_HPP
#define ITERATOR_BOOKSHELF_ITERATOR_HPP

#include "../common.hpp"

#include "iterator.hpp"
#include "bookshelf.hpp"

#include <memory>

namespace Is
{
    using std::shared_ptr;

    class Book;

    class DP_API BookShelfIterator /*: public Iterator*/
    {
        BookShelf* bookshelf_;
        int index_;

    // Java型イテレータ
    // public:
    //     BookShelfIterator(BookShelf* bookshelf)
    //         : bookshelf_(bookshelf), index_(0)
    //     {}
        
    //     bool hasNext() override;
    //     void* next() override;

    ////////////////////////////
    // C++型イテレータ(下記宣言)
    ////////////////////////////
    private:
        // privateなコンストラクタを呼び出せるようにfriend指定
        friend BookShelf;

        // イテレータを構築するコンストラクタはprivateにして、勝手に外部で作れないようにする
        BookShelfIterator();
        BookShelfIterator(BookShelf* bookshelf, int index);

    public:
        ~BookShelfIterator();

        // イテレータのコピー系はpublic指定
        BookShelfIterator(const BookShelfIterator& rhs);
        BookShelfIterator& operator=(const BookShelfIterator& rhs);

        // イテレータのムーブ系はpublic指定
        BookShelfIterator(BookShelfIterator&& rhs);
        BookShelfIterator& operator=(BookShelfIterator&& rhs);

    public:
        using value_type = Book;
        using difference_type = std::ptrdiff_t;
        using reference = Book&;
        using pointer = Book*;
        using iterator_category = std::random_access_iterator_tag;

        // ランダムアクセスイテレータに必要な演算定義
        /**
         * (*)     間接演算子
         * (->)    メンバ選択演算子 (イテレータの中身がクラス型なら有用かも)
         * ([])    添字演算子
         * (++a)   前置インクリメント
         * (a++)   後置インクリメント
         * (--a)   前置デクリメント
         * (a--)   後置デクリメント
         * (+=)    任意のインクリメント(1)
         * (a+n)   任意のインクリメント(2)
         * (-=)    任意のデクリメント(1)
         * (a-n)   任意のデクリメント(2)
         * (a==b)  等号
         * (a!=b)  不等号
         * (a>b)   比較
         * (a>=b)  比較等号
         * (a<b)   比較
         * (a<=b)  比較等号
         */

        // * 間接演算子
        const reference operator*() const;
        reference operator*();

        // // -> メンバ選択演算子
        // const reference operator->() const;
        // reference operator->();

        // [] 添字演算子
        const reference operator[](int n) const;
        reference operator[](int n);

        // += 任意のインクリメント(1)
        BookShelfIterator& operator+=(int n);

        // a+n 任意のインクリメント(2)
        BookShelfIterator& operator+(int n);

        // -= 任意のデクリメント(1)
        BookShelfIterator& operator-=(int n);

        // a-n 任意のデクリメント(2)
        BookShelfIterator& operator-(int n);

        // ++a 前置インクリメント
        BookShelfIterator& operator++();

        // a++ 後置インクリメント
        BookShelfIterator operator++(int);

        // --a 前置デクリメント
        BookShelfIterator& operator--();

        // a-- 後置デクリメント
        BookShelfIterator operator--(int);

        // a==b 等号
        bool operator==(const BookShelfIterator& iter) const;

        // a!=b 符号
        bool operator!=(const BookShelfIterator& iter) const;

        // a>b 比較
        bool operator>(const BookShelfIterator& iter) const;

        // a>=b 比較等号
        bool operator>=(const BookShelfIterator& iter) const;

        // a<b 比較
        bool operator<(const BookShelfIterator& iter) const;

        // a<=b 比較等号
        bool operator<=(const BookShelfIterator& iter) const;
    };
}
#endif