#ifndef STATE_SINGLETON_MANAGER_INTERNAL_HPP
#define STATE_SINGLETON_MANAGER_INTERNAL_HPP
#include "state_singleton_manager.hpp"

#include <iostream>
#include <typeinfo>
#include <cxxabi.h> // typeid().name()の戻り値をデマングルするためにつかう.

namespace Is
{
    template <typename SINGLETON>
    SINGLETON* StateSingletonManager::getInstance()
    {
        recursive_mutex& rmtx = getRecursiveMutex();
        std::unique_lock<std::recursive_mutex> locker(rmtx);

        static SINGLETON* instance{nullptr};
        if (instance)
        {
            return instance;
        }

        StateSingletonManager& self = StateSingletonManager::getSelf();
        instance = new SINGLETON{};

        // eraseById()でdeleterを呼んで, SingletonManagerが所有するSINGLETONインスタンスを削除する
        auto deleter = [&]() -> void {

            /* マングリングされたtypeid().name()の戻り値をデマングルしてクラス名を取得する */
            string singleton_name;
            const std::type_info& id = typeid(SINGLETON); // RTTI(Run Time Type Identifier)
            int stat;
            char* name = abi::__cxa_demangle(id.name(), 0, 0, &stat);
            if (name != nullptr)
            {
                if (stat == 0) // stats == 0で成功
                {
                    singleton_name = name;
                    ::free(name);
                }
            }

            std::cout << "Delete instance: " << singleton_name << std::endl;

            delete instance;
            instance = nullptr;
        };

        int id = self.count_;
        // self.singletons_.insert(std::make_pair(id, std::make_pair((uintptr_t)instance, deleter)));
        // self.singletons_.insert({id, {(uintptr_t)instance, deleter}});
        self.singletons_.emplace(id, std::make_pair((uintptr_t)instance, deleter));
        self.address2id_.emplace((uintptr_t)instance, id);

        self.count_ += 1;
        return instance;
    }

    template <typename SINGLETON>
    int StateSingletonManager::getId()
    {
        StateSingletonManager& self = StateSingletonManager::getSelf();
        auto address = (uintptr_t)StateSingletonManager::getInstance<SINGLETON>();
        return self.address2id_[address]; // id
    }

    template <typename SINGLETON>
    void StateSingletonManager::erase()
    {
        eraseById(StateSingletonManager::getId<SINGLETON>());
    }


/** Template instantiation to register a Singleton to SingletonManager.
 */
// dllライブラリのExportに対応するために、*.cppファイルでDLL_EXPORT_API付きで明示的インスタンス化
#define STATE_INSTANTIATE_SINGLETON(API, SINGLETON_CLASS)                                   \
  template API SINGLETON_CLASS *StateSingletonManager::getInstance<SINGLETON_CLASS>();      \
  template API int StateSingletonManager::getId<SINGLETON_CLASS>();                         \
  template API void StateSingletonManager::erase<SINGLETON_CLASS>()
}
#endif
