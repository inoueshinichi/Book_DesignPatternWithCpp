#ifndef __SINGLETON_SINGLETON_MANAGER_INTERNAL_HPP__
#define __SINGLETON_SINGLETON_MANAGER_INTERNAL_HPP__

#include "singleton_manager.hpp"

#include <iostream>

namespace Is
{
    /**
     * @brief 
     * static
     * @tparam SINGLETON 
     * @return SINGLETON* 
     */
    template<typename SINGLETON> 
    SINGLETON* SingletonManager::getInstance()
    {
        recursive_mutex& rmtx = getRecursiveMutex();
        std::unique_lock<std::recursive_mutex> locker(rmtx);

        static SINGLETON* instance = nullptr;
        if (instance)
        {
            return instance;
        }

        SingletonManager& self = getSelf();

        instance = new SINGLETON{};

        // eraseById()でdeleterを呼んで, SingletonManagerが所有するSINGLETONインスタンスを削除する
        auto deleter = [&]() -> void {
            std::cout << "Delete instance: " << typeid(SINGLETON).name() << std::endl;
            delete instance;
            instance = nullptr;
        };

        int id = self.count_;
        self.singletons_.insert({id, {(uintptr_t)instance, deleter}}); // unordered_map<int, pair<uintptr_t, function<void()>>>
        self.address2id_.insert({(uintptr_t)instance, id});            // unordered_map<uintptr_t, int>
        self.count_ += 1;
        return instance;
    }

    /**
     * @brief 
     * static
     * @tparam SINGLETON 
     * @return int 
     */
    template <typename SINGLETON> int SingletonManager::getId()
    {
        SingletonManager& self = getSelf();
        auto address = (uintptr_t)getInstance<SINGLETON>();
        return self.address2id_[address];
    }

    /**
     * @brief 
     * static
     * @tparam SINGLETON 
     */
    template <typename SINGLETON> void SingletonManager::erase()
    {
        eraseById(getId<SINGLETON>());
    }
}
#endif