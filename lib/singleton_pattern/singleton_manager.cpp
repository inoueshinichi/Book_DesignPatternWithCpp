#include "singleton_pattern/singleton_manager-internal.hpp"

namespace Is
{
    SingletonManager *SingletonManager::self_ = nullptr;

    recursive_mutex& SingletonManager::getRecursiveMutex()
    {
        static recursive_mutex rmtx_{};
        return rmtx_;
    }

    SingletonManager& SingletonManager::getSelf()
    {
        // コンストラクタで構築中のオブジェクトには、
        // 他スレッドから並行アクセスする手段が存在しないため、
        // コンストラクタ内処理が非staticメンバ変数への
        // アクセスのみならば排他制御の必然性がありません。
        // https://qiita.com/BugDig/items/80364b4e1c28b1685ab1
        
        // 今回は, コンストラクタ構築中にstatic変数count_にアクセスするので、
        // 排他制御が必要と思われる.
        recursive_mutex& rmtx = getRecursiveMutex();
        std::lock_guard<std::recursive_mutex> locker(rmtx);
        if (!self_)
        {
            self_ = new SingletonManager();
        }
        return *self_;
    }

    void SingletonManager::eraseById(int id)
    {
        SingletonManager& self = getSelf();
        auto iter = self.singletons_.find(id);

        if (iter == self.singletons_.end())
        {
            return;
        }
        
       iter->second.second(); // deleter instance
       self.address2id_.erase(iter->first); // erase the pair of (address, id) 
       self.singletons_.erase(iter); // erase (id, pair<address, deleter>)
    }

    void SingletonManager::clear()
    {
        SingletonManager& self = getSelf();

        for (int i = 0; i < self.count_; ++i)
        {
            eraseById(i);
        }

        // clear all
        self.singletons_.clear();
        self.address2id_.clear();
        self.count_ = 0;
    }
}
