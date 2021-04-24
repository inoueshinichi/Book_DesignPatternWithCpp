#ifndef STATE_SINGLETON_MANAGER_HPP
#define STATE_SINGLETON_MANAGER_HPP

#include "../common.hpp"

#include <memory>
#include <mutex>
#include <unordered_map>
#include <functional>
#include <string>

namespace Is
{
    using std::unordered_map;
    using std::pair;
    using std::function;
    using std::recursive_mutex;
    using std::string;

    class DP_API StateSingletonManager
    {
        static StateSingletonManager* self_;
        unordered_map<int, pair<uintptr_t, function<void()>>> singletons_;
        unordered_map<uintptr_t, int> address2id_;
        int count_;
        
        StateSingletonManager() : count_(0) {}
        ~StateSingletonManager() { clear(); }
        StateSingletonManager(const StateSingletonManager&) = delete;
        StateSingletonManager& operator=(const StateSingletonManager&) = delete;
        static StateSingletonManager& getSelf();
        static recursive_mutex& getRecursiveMutex();

    public:
        template <typename SINGLETON> static SINGLETON* getInstance();
        template<typename SINGLETON> static int getId();
        template<typename SINGLETON> static void erase();
        static void eraseById(int id);
        static void clear();
    };
}
#endif