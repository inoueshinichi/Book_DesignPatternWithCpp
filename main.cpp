#include <iostream>
#include <fstream>
#include <iomanip>

// Iterator Pattern
#include "iterator_pattern/book.hpp"
#include "iterator_pattern/bookshelf.hpp"
#include "iterator_pattern/iterator.hpp"

// Adapter Pattern
#include "adapter_pattern/printbanner.hpp"
//#include "adapter_pattern/print.hpp"

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

// Abstract Factory Pattern
#include "abstract_factory_pattern/abstract_factory.hpp"
#include "abstract_factory_pattern/list_factory/listfactory.hpp"
#include "abstract_factory_pattern/table_factory/table_factory.hpp"

// Bridge Pattern
#include "bridge_pattern/display.hpp"
#include "bridge_pattern/countdisplay.hpp"
#include "bridge_pattern/displayimpl.hpp"
#include "bridge_pattern/stringdisplayimpl.hpp"

// Strategy Pattern
#include "strategy_pattern/hand.hpp"
#include "strategy_pattern/player.hpp"
#include "strategy_pattern/strategy.hpp"
#include "strategy_pattern/winningstrategy.hpp"
#include "strategy_pattern/probstrategy.hpp"
#include <random> // std::random_deviceエンジン

// Composite Pattern
#include "composite_pattern/entry.hpp"
#include "composite_pattern/file.hpp"
#include "composite_pattern/directory.hpp"
#include "exception.hpp"

// Decorator Pattern
#include "decorator_pattern/display.hpp"
#include "decorator_pattern/stringdisplay.hpp"
#include "decorator_pattern/border.hpp"
#include "decorator_pattern/sideborder.hpp"
#include "decorator_pattern/fullborder.hpp"

// Visitor Pattern
#include "visitor_pattern/visitor.hpp"
#include "visitor_pattern/list_visitor.hpp"
#include "visitor_pattern/vi_file.hpp"
#include "visitor_pattern/vi_directory.hpp"

// Chain of Responsibility Pattern
#include "chain_of_responsibility_pattern/trouble.hpp"
#include "chain_of_responsibility_pattern/support.hpp"
#include "chain_of_responsibility_pattern/no_support.hpp"
#include "chain_of_responsibility_pattern/limit_support.hpp"
#include "chain_of_responsibility_pattern/odd_support.hpp"
#include "chain_of_responsibility_pattern/special_support.hpp"

// Facade Pattern 
#include <nlohmann/json.hpp> // third_party
#include "facade_pattern/pagemaker.hpp"

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

    auto print_sp = static_pointer_cast<Print>(make_shared<PrintBanner>("Hello"));
    print_sp->printWeak();
    print_sp->printStrong();
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
    auto card1 = factory->create("Inoue A");
    auto card2 = factory->create("Inoue B");
    auto card3 = factory->create("Inoue C");
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


void pattern_abstract_factory()
{
    std::printf("==================== pattern_abstract_factory() ====================\n");
    using namespace Is;

    // Register
    AbstractFactory::addFactory<ListFactory>();

    // Use
    auto factory = std::static_pointer_cast<AbstractFactory>(AbstractFactory::getFactory("Is::ListFactory"));
    shared_ptr<Link> asahi = factory->createLink("朝日新聞", "http://www.asahi.com/");
    shared_ptr<Link> yomiuri = factory->createLink("読売新聞", "http://www.yomiuri.com/");
    shared_ptr<Link> us_yahoo = factory->createLink("Yahoo!", "http://www.yahoo.com/");
    shared_ptr<Link> jp_yahoo = factory->createLink("Yahoo!Japan", "http://www.yahoo.co.jp/");
    shared_ptr<Link> excite = factory->createLink("Excite", "http://www.excite.com/");
    shared_ptr<Link> google = factory->createLink("Google", "http://www.google.com/");

    shared_ptr<Tray> traynews = factory->createTray("新聞");
    traynews->add(std::static_pointer_cast<Item>(asahi));
    traynews->add(std::static_pointer_cast<Item>(yomiuri));

    shared_ptr<Tray> trayyahoo = factory->createTray("Yahoo!");
    trayyahoo->add(std::static_pointer_cast<Item>(us_yahoo));
    trayyahoo->add(std::static_pointer_cast<Item>(jp_yahoo));

    shared_ptr<Tray> traysearch = factory->createTray("サーチエンジン");
    traysearch->add(std::static_pointer_cast<Item>(trayyahoo));
    traysearch->add(std::static_pointer_cast<Item>(excite));
    traysearch->add(std::static_pointer_cast<Item>(google));

    auto page = factory->createPage("LinkPage", "Inoue Shinichi");
    page->add(std::static_pointer_cast<Item>(traynews));
    page->add(std::static_pointer_cast<Item>(traysearch));
    page->output();


    // Register
    AbstractFactory::addFactory<TableFactory>();

    // Use
    auto factory_2 = std::static_pointer_cast<AbstractFactory>(AbstractFactory::getFactory("Is::TableFactory"));
    auto asahi_2 = factory_2->createLink("朝日新聞", "http://www.asahi.com/");
    auto yomiuri_2 = factory_2->createLink("読売新聞", "http://www.yomiuri.com/");
    auto us_yahoo_2 = factory->createLink("Yahoo!", "http://www.yahoo.com/");
    auto jp_yahoo_2 = factory->createLink("Yahoo!Japan", "http://www.yahoo.co.jp/");
    auto excite_2 = factory->createLink("Excite", "http://www.excite.com/");
    auto google_2 = factory->createLink("Google", "http://www.google.com/");

    auto traynews_2 = factory_2->createTray("新聞");
    traynews_2->add(std::static_pointer_cast<Item>(asahi_2));
    traynews_2->add(std::static_pointer_cast<Item>(yomiuri_2));

    auto trayyahoo_2 = factory_2->createTray("Yahoo!");
    trayyahoo_2->add(std::static_pointer_cast<Item>(us_yahoo_2));
    trayyahoo_2->add(std::static_pointer_cast<Item>(jp_yahoo_2));

    auto traysearch_2 = factory_2->createTray("サーチエンジン");
    traysearch_2->add(std::static_pointer_cast<Item>(trayyahoo_2));
    traysearch_2->add(std::static_pointer_cast<Item>(excite_2));
    traysearch_2->add(std::static_pointer_cast<Item>(google_2));

    auto page_2 = factory_2->createPage("TablePage", "Inoue Shinichi");
    page_2->add(std::static_pointer_cast<Item>(traynews_2));
    page_2->add(std::static_pointer_cast<Item>(traysearch_2));
    page_2->output();
}


void pattern_bridge()
{
    std::printf("==================== pattern_bridge() ====================\n");
    using namespace Is;
    using namespace std;

    // 1
    unique_ptr<StringDisplayImpl> d1_impl(new StringDisplayImpl("Hello, 日本."));
    shared_ptr<Display> d1 = make_shared<Display>(move(d1_impl));

    // 2
    auto d2_impl = make_unique<StringDisplayImpl>("Hello, World.");
    shared_ptr<Display> d2 = static_pointer_cast<Display>(make_shared<CountDisplay>(move(d2_impl)));

    // 3
    shared_ptr<CountDisplay> d3 = make_shared<CountDisplay>(move(make_unique<StringDisplayImpl>("Hello, Universe.")));

    // 出力
    d1->display();
    d2->display();
    d3->display();
    d3->multiDisplay(3);
}


void pattern_strategy()
{
    std::printf("==================== pattern_strategy() ====================\n");
    using namespace Is;
    using namespace std;

    random_device rd; // 完全ランダムエンジン
    int seed1 = (int)rd(); // rd()は符号なし32bit整数を返す
    int seed2 = (int)rd();
    cout << "seed1: " << seed1 << " for Taro, seed2: " << seed2 << " for Hana" << endl;

    Player player1("Taro", move(make_unique<WinningStrategy>(seed1)));
    Player player2("Hana", move(make_unique<ProbStrategy>(seed2)));

    // 100回のじゃんけんゲーム
    for (int game_index = 0; game_index < 100; ++game_index)
    {
        Hand nextHand1 = player1.nextHand();
        Hand nextHand2 = player2.nextHand();

        if (nextHand1.isStrongerThan(nextHand2))
        {
            cout << "Winner: " << "player1" << endl;
            player1.win();
            player2.lose();
        }
        else if (nextHand2.isStrongerThan(nextHand1))
        {
            cout << "Winner: " << "player2" << endl;
            player1.lose();
            player2.win();
        }
        else
        {
            cout << "Even..." << endl;
            player1.even();
            player2.even();
        }
    }

    cout << "Total result: " << endl;
    cout << player1.toString() << endl;
    cout << player2.toString() << endl;
}

void pattern_composite()
{
    std::printf("==================== pattern_composite() ====================\n");
    using namespace Is;
    using namespace std;

    try
    {
        cout << "Making root entries..." << endl;
        auto root_dir = make_shared<Directory>("root");
        auto bin_dir = make_shared<Directory>("bin");
        auto tmp_dir = make_shared<Directory>("tmp");
        auto usr_dir = make_shared<Directory>("usr");
        root_dir->add(bin_dir);
        root_dir->add(tmp_dir);
        root_dir->add(usr_dir);
        bin_dir->add(make_shared<File>("vi", 10000));
        bin_dir->add(make_shared<File>("latex", 20000));
        root_dir->printList();

        cout << endl;
        cout << "Making user entries..." << endl;
        auto yuki = make_shared<Directory>("yuki");
        auto hanako = make_shared<Directory>("hanako");
        auto tomura = make_shared<Directory>("tomura");
        usr_dir->add(yuki);
        usr_dir->add(hanako);
        usr_dir->add(tomura);
        yuki->add(make_shared<File>("diary.html", 100));
        yuki->add(make_shared<File>("composite.cpp", 200));
        hanako->add(make_shared<File>("memo.txt", 300));
        tomura->add(make_shared<File>("game.doc", 400));
        tomura->add(make_shared<File>("junk.mail", 500));
        root_dir->printList();
    }
    catch(Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void pattern_decorator()
{
    std::printf("==================== pattern_decorator() ====================\n");
    using namespace Is;
    using namespace std;

    auto b1 = static_pointer_cast<DecoBaseDisplay>(make_shared<DecoStringDisplay>("Hello, World."));
    shared_ptr<DecoBaseDisplay> b2 = make_shared<SideBorder>(b1, '#');
    shared_ptr<DecoBaseDisplay> b3 = make_shared<FullBorder>(b2);
    b1->show();
    b2->show();
    b3->show();

    shared_ptr<DecoBaseDisplay> b4 = make_shared<SideBorder>(
        make_shared<FullBorder>(
            make_shared<SideBorder>(
                make_shared<FullBorder>(
                    make_shared<DecoStringDisplay>("Hello C++!!!")
                ), '*'
            )
        ), '/'
    );

    b4->show();
}

void pattern_visitor()
{
    std::printf("==================== pattern_visitor() ====================\n");
    using namespace Is;
    using namespace std;

    try
    {
        cout << "Making root entries..." << endl;
        auto root_dir = ViDirectory::create("root");
        auto bin_dir = ViDirectory::create("bin");
        auto tmp_dir = ViDirectory::create("tmp");
        auto usr_dir = ViDirectory::create("usr");
        root_dir->add(bin_dir);
        root_dir->add(tmp_dir);
        root_dir->add(usr_dir);
        bin_dir->add(ViFile::create("vi", 10000));
        bin_dir->add(ViFile::create("latex", 20000));
        root_dir->accept(ListVisitor::create());

        cout << endl;
        cout << "Making user entries..." << endl;
        auto yuki = ViDirectory::create("yuki");
        auto hanako = ViDirectory::create("hanako");
        auto tomura = ViDirectory::create("tomura");
        usr_dir->add(yuki);
        usr_dir->add(hanako);
        usr_dir->add(tomura);
        yuki->add(ViFile::create("diary.html", 100));
        yuki->add(ViFile::create("Composite.cpp", 200));
        hanako->add(ViFile::create("memo.tex", 300));
        tomura->add(ViFile::create("game.doc", 400));
        tomura->add(ViFile::create("junk.mail", 500));
        root_dir->accept(ListVisitor::create());
    }
    catch(Exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void pattern_chain_of_responsibility()
{
    std::printf("==================== pattern_chain_of_responsibility() ====================\n");
    using namespace Is;
    using namespace std;

    auto alice = make_shared<NoSupport>("Alice");
    auto bob = make_shared<LimitSupport>("Bob", 100);
    auto charlie = make_shared<SpecialSupport>("charlie", 429);
    auto diana = make_shared<LimitSupport>("Diana", 200);
    auto elmo = make_shared<OddSupport>("Elmo");
    auto fred = make_shared<LimitSupport>("Fred", 300);

    // 連鎖の形成
    alice->setNext(bob)->setNext(charlie)->setNext(diana)->setNext(elmo)->setNext(fred);

    // 様々なトラブルが発生
    for (int i = 0; i < 500; i += 33)
    {
        alice->support(make_shared<Trouble>(i));
    }
}

void pattern_facade()
{
    std::printf("==================== pattern_facade() ====================\n");
    using namespace Is;
    using namespace std;
    using json = nlohmann::json;

    // JSONフォーマットの設定データ作成
    json json_mail_data;
    json_mail_data["hyuki@hyuki.com"] = "Hiroshi Yuki";
    json_mail_data["hanako@hyuki.com"] = "Hanako Sato";
    json_mail_data["tomura@hkyuki.com"] = "Tomura";
    json_mail_data["mamoru@hkyuki.com"] = "Mamoru Takahashi";

    // ファイルに書き出し(シリアライズ)
    ofstream ofs("maildata.json");
    ofs << std::setw(4) << json_mail_data << std::endl;

    // Htmlファイルの作成
    PageMaker::makeWelcomPage("hyuki@hyuki.com", "welcom.html");
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
    pattern_abstract_factory();
    pattern_bridge();
    pattern_strategy();
    pattern_composite();
    pattern_decorator();
    pattern_visitor();
    pattern_chain_of_responsibility();
    pattern_facade();

    return 0;
}
