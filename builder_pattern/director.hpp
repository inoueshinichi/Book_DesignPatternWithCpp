#ifndef __DIRECTOR_HPP__
#define __DIRECTOR_HPP__"

#include "builder.hpp"

#include <memory>

namespace Is
{
    using std::shared_ptr;

    class Director
    {
        shared_ptr<Builder> builder;

    public:
        Director(shared_ptr<Builder> builder)
            : builder(builder)
        {}

        void construct()
        {
            builder->makeTitle("Greeting");
            builder->makeString("朝から昼にかけて");
            vector<string> items = { string("おはようございます."), string("こんにちは.") };
            builder->makeItems(items);
            builder->makeString(string("夜に"));
            builder->makeItems(vector<string>{string("こんばんは."), 
                                              string("おやすみなさい."), 
                                              string("さようなら.")});
            builder->close();
        }
    }
}

#endif