#include <iostream>

// Prototype Pattern
#include "prototype_pattern/product.hpp"
#include "prototype_pattern/underline.hpp"
#include "prototype_pattern/messagebox.hpp"
#include "prototype_pattern/manager.hpp"

void pattern_prototype()
{
    // 登録
    auto upen = static_cast<std::shared_ptr<Is::Product>>(std::make_shared<Is::UnderlinePen>("~"));
    Is::Manager::register_("strong message", upen);
    auto mbox = static_cast<std::shared_ptr<Is::Product>>(std::make_shared<Is::MessageBox>("*"));
    Is::Manager::register_("warning box", mbox);
    auto sbox = static_cast<std::shared_ptr<Is::Product>>(std::make_shared<Is::MessageBox>("/"));
    Is::Manager::register_("slash box", sbox);

    // 生成
    auto p1 = Is::Manager::create("strong message");
    p1->use("Hello, world.");
    auto p2 = Is::Manager::create("warning box");
    p2->use("Hello, world.");
    auto p3 = Is::Manager::create("slash box");
    p3->use("Hello, world.");
}


int main(int, char**) 
{    
    pattern_prototype();
    return 0;
}
