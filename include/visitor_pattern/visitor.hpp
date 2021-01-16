#ifndef VISITOR_VISITOR_HPP
#define VISITOR_VISITOR_HPP

#include "../common.hpp"

#include <memory>

namespace Is
{
    using std::shared_ptr;

    class ViFile;
    class ViDirectory;

    class DP_API Visitor
    {
    public:
        Visitor() {}
        virtual ~Visitor() {}

        void visit(shared_ptr<ViFile> file)
        {
            this->visit_impl(file);
        }

        void visit(shared_ptr<ViDirectory> directory)
        {
            this->visit_impl(directory);
        }

    protected:
        virtual void visit_impl(shared_ptr<ViFile> file) = 0;
        virtual void visit_impl(shared_ptr<ViDirectory> directory) = 0;
    };
}
#endif