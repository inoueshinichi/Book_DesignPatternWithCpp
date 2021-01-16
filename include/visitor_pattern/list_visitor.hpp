#ifndef VISITOR_LISTVISITOR_HPP
#define VISITOR_LISTVISITOR_HPP

#include "../common.hpp"
#include "../exception.hpp"
#include "visitor.hpp"
#include "vi_file.hpp"
#include "vi_directory.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <sstream>

namespace Is
{
    using std::shared_ptr;
    using std::make_shared;
    using std::string;
    using std::stringstream;

    class DP_API ListVisitor : public Visitor, public std::enable_shared_from_this<ListVisitor>
    {
        string current_dir_;

        // shared_from_this()を呼び出す前に、shared_ptr<ListVisitor>のインスタンスが必要になる.
        // 生ポインタ経由でListVisitorの使用を利用者に禁止するために、コンストラクタはprivateにする必要がある.
        // そして、shared_ptr<ListVisitor>はクラスのファクトリ関数経由で生成するような設計にすること.
        ListVisitor() {}

    public:
        virtual ~ListVisitor() {}

        // ファクトリー関数
        static shared_ptr<ListVisitor> create()
        {
            // return make_shared<ListVisitor>(); // ListVisitorのコンストラクタがprivateだとコンパイルエラー
            return shared_ptr<ListVisitor>(new ListVisitor());
        }

    protected:
        virtual void visit_impl(shared_ptr<ViFile> file) override
        {
            std::cout << current_dir_ << "/" << file->getName() << std::endl;
        }

        virtual void visit_impl(shared_ptr<ViDirectory> directory) override
        {
            std::cout << current_dir_ << "/" << directory->getName() << std::endl;

            string save_dir = current_dir_;
            current_dir_ = current_dir_ + "/" + directory->getName();
            auto entries = directory->entries();
            for (auto entry : entries)
            {
                string class_name = entry->getClassName();
                if (class_name.compare(string("File")) == 0)
                {
                    auto derived_file = std::dynamic_pointer_cast<ViFile>(entry);
                    derived_file->accept(std::static_pointer_cast<Visitor>(shared_from_this()));

                }
                else if (class_name.compare(string("Directory")) == 0)
                {
                    auto derived_directory = std::dynamic_pointer_cast<ViDirectory>(entry);
                    derived_directory->accept(std::static_pointer_cast<Visitor>(shared_from_this()));
                }
                else
                {
                    IS_ERROR(error_code::unclassified, "Class name does not match either `File` or `Directory`. Given is %s", class_name.c_str());
                }
            }

            current_dir_ = save_dir; // 一つ上の階層に戻る
        }
    };
}
#endif