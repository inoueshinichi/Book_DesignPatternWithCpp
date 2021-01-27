#ifndef MEMENTO_GAMER_HPP
#define MEMENTO_GAMER_HPP

#include "../common.hpp"
#include "memento.hpp"

#include <vector>
#include <memory>
#include <random>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>

namespace Is
{
    using std::string;
    using std::vector;
    using std::shared_ptr;
    using std::make_shared;
    using std::mt19937_64;
    using std::uniform_int_distribution;
    using std::random_device;

    class DP_API Gamer
    {
        int money_;
        random_device rd_;
        mt19937_64 engine_;
        vector<string> fruits_;

        string getFruit()
        {
            string prefix = "";
            std::bernoulli_distribution ber_dist(0.5); // 0.5の確率でtrue, (1.0 - 0.5)の確率でfalseを生成.
            if (ber_dist(engine_))
            {
                prefix = "おいしい";
            }

            uniform_int_distribution<int> uni_dist(0, 3);
            string ret = prefix + fruits_name[uni_dist(engine_)];
            return ret;
        }

    public:
        static const string fruits_name[];

        Gamer(int money) : money_(money)
        {
            int seed = rd_(); // uint32
            engine_.seed(seed);
        }

        ~Gamer() {}

        int getMoney()
        {
            return money_;
        }

        // サイコロを振るゲームを行う
        void bet () 
        {
            uniform_int_distribution<int> dist(1, 6);

            if (int dice = dist(engine_); dice == 1)
            {
                money_ += 100;
                std::cout << "所持金が増えました." << std::endl;
            }
            else if (dice == 2)
            {
                money_ /= 2;
                std::cout << "所持金が半分になりました." << std::endl;
            }
            else if (dice == 6)
            {
                string f = getFruit();
                std::printf("フルーツ(%s)をもらいました.\n", f.c_str());
                fruits_.push_back(f);
            }
            else
            {
                std::cout << "何も起こりませんでした." << std::endl;
            }
        }

        shared_ptr<Memento> createMement()
        {
            auto mem = Memento::create(money_);
            for (auto& fruit : fruits_)
            {
                if (fruit.starts_with("おいしい"))
                {
                    mem->addFruit(fruit);
                }
            }

            return mem;
        }

        void restoreMemento(shared_ptr<Memento> memento)
        {
            money_ = memento->getMoney();
            fruits_ = memento->getFruits();
        }

        string operator()()
        {
            std::stringstream ss;
            ss << "[money = ";
            ss << money_;
            ss << ", fruits = ";
            for (size_t enumerate = 1; auto& fruit : fruits_)
            {
                ss << fruit;
                if (enumerate != fruits_.size())
                {
                    ss << ", ";
                }  
                enumerate++;
            }
            ss << "]";
            ss << "\n";
            return ss.str();
        }


    };

    const string Gamer::fruits_name[] = {
        "リンゴ", "ぶどう", "バナナ", "みかん"
    };
}
#endif