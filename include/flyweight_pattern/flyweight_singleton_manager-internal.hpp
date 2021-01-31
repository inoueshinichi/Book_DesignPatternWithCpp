#ifndef FLYWEIGHT_SINGLETON_MANAGER_INTERNAL_HPP
#define FLYWEIGHT_SINGLETON_MANAGER_INTERNAL_HPP

#include "flyweight_singleton_manager.hpp"

#include <iostream>

namespace Is
{
    template<typename SINGLETON> 
    SINGLETON* FlyweightSingletonManager::getInstance()
    {
        recursive_mutex& rmtx = getRecursiveMutex();
        std::unique_lock<std::recursive_mutex> locker(rmtx);

        static SINGLETON* instance = nullptr;
        if (instance)
        {
            return instance;
        }

        FlyweightSingletonManager& self = getSelf();

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

    template <typename SINGLETON> int FlyweightSingletonManager::getId()
    {
        FlyweightSingletonManager& self = getSelf();
        auto address = (uintptr_t)getInstance<SINGLETON>();
        return self.address2id_[address];
    }

    template <typename SINGLETON> void FlyweightSingletonManager::erase()
    {
        eraseById(getId<SINGLETON>());
    }

/** Template instantiation to register a Singleton to SingletonManager.
 */
// dllライブラリのExportに対応するために、Templateを実体化するクラスの*.cppファイルに下記マクロを記述する
#define FLYWEIGHT_INSTANTIATE_SINGLETON(API, SINGLETON_CLASS)                            \
  template API SINGLETON_CLASS *FlyweightSingletonManager::getInstance<SINGLETON_CLASS>();      \
  template API int FlyweightSingletonManager::getId<SINGLETON_CLASS>();                \
  template API void FlyweightSingletonManager::erase<SINGLETON_CLASS>()
}
#endif
