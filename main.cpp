#include <iostream>

// Singleton Pattern
#include "singleton_pattern/singleton_manager-internal.hpp"
#include "singleton_pattern/singleton.hpp"

// Prototype Pattern
#include "prototype_pattern/product.hpp"
#include "prototype_pattern/underline.hpp"
#include "prototype_pattern/messagebox.hpp"
#include "prototype_pattern/manager.hpp"

// Builder Pattern
#include "builder_pattern/builder.hpp"
#include "builder_pattern/director.hpp"
#include "builder_pattern/textbuilder.hpp"
#include "builder_pattern/htmlbuilder.hpp"



void pattern_singleton()
{
    std::printf("==================== pattern_singleton() ====================\n");
    using namespace Is;

    auto cpu_1 = SingletonManager::getInstance<Cpu>();
    auto cpu_2 = SingletonManager::getInstance<Cpu>();

    if (cpu_1 == cpu_2)
    {
        std::printf("Cpu_1 is the same as Cpu_2; %p == %p\n", cpu_1, cpu_2);
    }
    else
    {
        std::printf("Cpu_1 is NOT the same as Cpu_2; %p != %p\n", cpu_1, cpu_2);
    }

    auto gpu_1 = SingletonManager::getInstance<Gpu>();
    auto gpu_2 = SingletonManager::getInstance<Gpu>();

    if (gpu_1 == gpu_2)
    {
        std::printf("Gpu_1 is the same as Gpu_2; %p == %p\n", gpu_1, gpu_2);
    }
    else
    {
        std::printf("Gpu_1 is NOT the same as Gpu_2; %p != %p\n", gpu_1, gpu_2);
    }
    

    std::cout << "今後は、Multi-thread 環境でSingletonManagerが正常動作するかチェック." << std::endl;


}

void pattern_prototype()
{
    std::printf("==================== pattern_prototype() ====================\n");

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


void pattern_builder()
{
    std::printf("==================== pattern_builder() ====================\n");
    using namespace Is;

    auto textbuilder = std::make_shared<TextBuilder>();
    Director director_1(static_cast<std::shared_ptr<Builder>>(textbuilder));
    director_1.construct();
    std::string result_1 = textbuilder->getResult();
    std::cout << result_1 << std::endl;

    auto htmlbuilder = std::make_shared<HTMLBuilder>();
    Director director_2(static_cast<std::shared_ptr<Builder>>(htmlbuilder));
    director_2.construct();
    std::string result_2 = htmlbuilder->getResult();
    std::cout << result_2 << std::endl;
}


int main(int, char**) 
{    
    pattern_singleton();
    pattern_prototype();
    pattern_builder();
    return 0;
}
