#ifndef VISITOR_VIDIRECTORY_HPP
#define VISITOR_VIDIRECTORY_HPP

#include "../common.hpp"
#include "element.hpp"
#include "../composite_pattern/directory.hpp"
#include "visitor.hpp"

#include <memory>
#include <string>
#include <vector>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;
    using std::vector;

    class DP_API ViDirectory : public Element, public Directory, public std::enable_shared_from_this<ViDirectory>
    {
        // shared_from_this()を呼び出す前に、shared_ptr<ViDirectory>のインスタンスが必要になる.
        // 生ポインタ経由でViDirecotryの使用を利用者に禁止するために、コンストラクタはprivateにする必要がある.
        // そして、shared_ptr<ViDirectory>はクラスのファクトリ関数経由で生成するような設計にすること.
        ViDirectory(const string& name) : Directory(name) {}
        
    public:
        virtual ~ViDirectory() {}

        // ファクトリー関数
        static shared_ptr<ViDirectory> create(const string& name)
        {
            // return make_shared<ViDirectory>(name); // ViDirectoryコンストラクタがprivateだとコンパイルエラー
            return shared_ptr<ViDirectory>(new ViDirectory(name));
        }

        virtual void accept(shared_ptr<Visitor> visitor) override
        {
            visitor->visit(shared_from_this());
        }
    };
}
#endif