#ifndef SINGLETON_SINGLETON_MANAGER_HPP
#define SINGLETON_SINGLETON_MANAGER_HPP

#include "../common.hpp"

// #include <thread>
#include <mutex>
#include <memory>
#include <unordered_map>
#include <functional>
#include <typeinfo>

namespace Is
{
    using std::unordered_map;
    using std::pair;
    using std::function;
    using std::recursive_mutex;

    class DP_API SingletonManager
    {
        // 変数
        static SingletonManager* self_;
        int count_;
        unordered_map<int, pair<uintptr_t, function<void()>>> singletons_;
        unordered_map<uintptr_t, int> address2id_;

        SingletonManager() : count_(0) {}
        ~SingletonManager() { clear(); }
        SingletonManager(const SingletonManager&) = delete;
        SingletonManager& operator=(const SingletonManager&) = delete;
        static SingletonManager& getSelf();
        static recursive_mutex& getRecursiveMutex();
        
    public:
        template<typename SINGLETON> static SINGLETON* getInstance();
        template<typename SINGLETON> static int getId();
        template<typename SINGLETON> static void erase();
        static void eraseById(int id);
        static void clear();
    };
}
#endif
