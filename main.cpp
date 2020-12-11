#include <iostream>

// Iterator Pattern
#include "iterator_pattern/book.hpp"
#include "iterator_pattern/bookshelf.hpp"
#include "iterator_pattern/iterator.hpp"

// Template_Method Pattern
#include "template_method_pattern/abstract_display.hpp"
#include "template_method_pattern/char_display.hpp"
#include "template_method_pattern/string_display.hpp"

// Factory_Method Pattern
#include "factory_method_pattern/factory.hpp"
#include "factory_method_pattern/idcard_factory.hpp"

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


void pattern_iterator()
{
    std::printf("==================== pattern_iterator() ====================\n");
    using namespace Is;
    using namespace std;

    BookShelf bookshelf(4);
    bookshelf.appendBook(std::move(Book("Around the World in 80 Days.")));
    bookshelf.appendBook(std::move(Book("Bible")));
    bookshelf.appendBook(std::move(Book("Cinderella")));
    bookshelf.appendBook(std::move(Book("Daddy-Long-Legs")));

    auto iter_sp = bookshelf.iterator();
    while (iter_sp->hasNext())
    {
        Book* book = static_cast<Book*>(iter_sp->next());
        std::cout << book->getName() << std::endl;
    }
}


void pattern_adapter()
{
    std::printf("==================== pattern_adapter() ====================\n");
    using namespace Is;
    using namespace std;
}


void pattern_template_method()
{
    std::printf("==================== pattern_template_method() ====================\n");
    using namespace Is;
    using namespace std;

    shared_ptr<AbstractDisplay> d1 = static_pointer_cast<AbstractDisplay>(make_shared<CharDisplay>('H'));
    shared_ptr<AbstractDisplay> d2 = static_pointer_cast<AbstractDisplay>(make_shared<StringDisplay>("Hello, world."));
    shared_ptr<AbstractDisplay> d3 = static_pointer_cast<AbstractDisplay>(make_shared<StringDisplay>("こんにちは。"));
    d1->display();
    d2->display();
    d3->display();
}


void pattern_factory_method()
{
    std::printf("==================== pattern_factory_method() ====================\n");
    using namespace Is;
    auto factory = std::static_pointer_cast<Factory>(std::make_shared<IdCardFactory>());
    auto card1 = factory->create("井上真一");
    auto card2 = factory->create("井上美里");
    auto card3 = factory->create("井上早織");
    card1->use();
    card2->use();
    card3->use();
}


void pattern_singleton()
{
    std::printf("==================== pattern_singleton() ====================\n");
    using namespace Is;

    auto cpu_1 = SingletonManager::getInstance<Cpu>();
    auto cpu_2 = SingletonManager::getInstance<Cpu>();

    if (cpu_1 == cpu_2)
    {
        std::printf("Cpu_1 is the same as Cpu_2; %p == %p\n", (void*)cpu_1, (void*)cpu_2);
    }
    else
    {
        std::printf("Cpu_1 is NOT the same as Cpu_2; %p != %p\n", (void*)cpu_1, (void*)cpu_2);
    }

    auto gpu_1 = SingletonManager::getInstance<Gpu>();
    auto gpu_2 = SingletonManager::getInstance<Gpu>();

    if (gpu_1 == gpu_2)
    {
        std::printf("Gpu_1 is the same as Gpu_2; %p == %p\n", (void*)gpu_1, (void*)gpu_2);
    }
    else
    {
        std::printf("Gpu_1 is NOT the same as Gpu_2; %p != %p\n", (void*)gpu_1, (void*)gpu_2);
    }
    

    std::cout << "今後は、Multi-thread 環境でSingletonManagerが正常動作するかチェック." << std::endl;


}

void pattern_prototype()
{
    std::printf("==================== pattern_prototype() ====================\n");
    using namespace Is;

    // 登録
    auto upen = std::static_pointer_cast<Product>(make_shared<Is::UnderlinePen>("~"));
    Is::Manager::register_("strong message", upen);
    auto mbox = std::static_pointer_cast<Product>(std::make_shared<Is::MessageBox>("*"));
    Is::Manager::register_("warning box", mbox);
    auto sbox = std::static_pointer_cast<Product>(std::make_shared<Is::MessageBox>("/"));
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
    Director director_1(std::static_pointer_cast<Builder>(textbuilder));
    director_1.construct();
    std::string result_1 = textbuilder->getResult();
    std::cout << result_1 << std::endl;

    auto htmlbuilder = std::make_shared<HTMLBuilder>();
    Director director_2(std::static_pointer_cast<Builder>(htmlbuilder));
    director_2.construct();
    std::string result_2 = htmlbuilder->getResult();
    std::cout << result_2 << std::endl;
}


int main(int, char**) 
{  
    pattern_iterator();
    pattern_adapter();
    pattern_template_method();
    pattern_factory_method();  
    pattern_singleton();
    pattern_prototype();
    pattern_builder();
    return 0;
}
