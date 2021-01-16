#ifndef VISITOR_VIFILE_HPP
#define VISITOR_VIFILE_HPP

#include "../common.hpp"
#include "element.hpp"
#include "../composite_pattern/file.hpp"
#include "visitor.hpp"

#include <memory>
#include <string>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::make_shared;

    class DP_API ViFile : public Element, public File, public std::enable_shared_from_this<ViFile>
    {
        // shared_from_this()を呼び出す前に、shared_ptr<ViFile>のインスタンスが必要になる.
        // 生ポインタ経由でViFileの使用を利用者に禁止するために、コンストラクタはprivateにする必要がある.
        // そして、shared_ptr<ViFile>はクラスのファクトリ関数経由で生成するような設計にすること.
        ViFile(const string& name, int size) : File(name, size) {}

    public:
        virtual ~ViFile() {}

        // ファクトリー関数
        static shared_ptr<ViFile> create(const string& name, int size)
        {
            // return make_shared<ViFile>(name, size); // ViFileコンストラクタがprivateだとコンパイルエラー
            return shared_ptr<ViFile>(new ViFile(name, size));
        }

        virtual void accept(shared_ptr<Visitor> visitor) override
        {
            visitor->visit(shared_from_this());
        }
    };
}
#endif