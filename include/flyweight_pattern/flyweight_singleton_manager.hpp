#ifndef FLYWEIGHT_SINGLETON_MANAGER_HPP
#define FLYWEIGHT_SINGLETON_MANAGER_HPP

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

    class DP_API FlyweightSingletonManager
    {
        // 変数
        static FlyweightSingletonManager* self_;
        int count_;
        unordered_map<int, pair<uintptr_t, function<void()>>> singletons_;
        unordered_map<uintptr_t, int> address2id_;

        FlyweightSingletonManager() : count_(0) {}
        ~FlyweightSingletonManager() { clear(); }
        FlyweightSingletonManager(const FlyweightSingletonManager&) = delete;
        FlyweightSingletonManager& operator=(const FlyweightSingletonManager&) = delete;
        static FlyweightSingletonManager& getSelf();
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
