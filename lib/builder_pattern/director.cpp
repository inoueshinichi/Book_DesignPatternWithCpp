#include "builder_pattern/director.hpp"

namespace Is
{
    /**
     * @brief Construct a new Director:: Cirector object
     * 
     * @param builder 
     */
    Director::Director(shared_ptr<Builder> builder)
        : builder_(builder)
    {}


    /**
     * @brief 
     * 
     */
    void Director::construct()
    {
        builder_->makeTitle("Greeting");
        builder_->makeString("朝から昼にかけて");
        vector<string> items = { string("おはようございます."), string("こんにちは.") };
        builder_->makeItems(items);
        builder_->makeString(string("夜に"));
        builder_->makeItems(vector<string>{string("こんばんは."), 
                                            string("おやすみなさい."), 
                                            string("さようなら.")});
        builder_->close();
    }
}