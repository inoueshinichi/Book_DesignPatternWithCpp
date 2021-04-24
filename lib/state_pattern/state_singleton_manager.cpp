#include "state_pattern/state_singleton_manager-internal.hpp"

namespace Is
{
    StateSingletonManager* StateSingletonManager::self_ = nullptr;

    recursive_mutex& StateSingletonManager::getRecursiveMutex()
    {
        static recursive_mutex rmtx_{};
        return rmtx_;
    }

    StateSingletonManager& StateSingletonManager::getSelf()
    {
        // コンストラクタで構築中のオブジェクトには、
        // 他スレッドから並行アクセスする手段が存在しないため、
        // コンストラクタ内処理が非staticメンバ変数への
        // アクセスのみならば排他制御の必然性がありません。
        // https://qiita.com/BugDig/items/80364b4e1c28b1685ab1

        // 今回は, コンストラクタ構築中にstatic変数count_にアクセスするので、
        // 排他制御が必要と思われる.
        recursive_mutex& rmtx = StateSingletonManager::getRecursiveMutex();
        std::lock_guard<std::recursive_mutex> locker(rmtx);
        if (!self_)
        {
            self_ = new StateSingletonManager(); // private constructor, destructor
        }
        return *self_;
    }

    void StateSingletonManager::eraseById(int id)
    {
        StateSingletonManager& self = StateSingletonManager::getSelf();

        auto iter = self.singletons_.find(id);
        if (iter == self.singletons_.end())
        {
            return;
        }

        iter->second.second(); // invoke deleter: instanceアドレスのストレージ領域を削除
        // std::erase(self.address2id_, iter->first); // C++20 value値から要素を消す
        self.address2id_.erase(iter->second.first); // key値から要素を消す
        // std::erase(self.singletons_, iter->second.first);
        // self.singletons_.erase(iter); // iteratorから要素を消す
        self.singletons_.erase(iter->first); // key値から要素を消す
    }

    void StateSingletonManager::clear()
    {
        StateSingletonManager& self = StateSingletonManager::getSelf();
        for (int id = 0; id < self.count_; ++id)
        {
            eraseById(id); // Delete if it's active.
        }

        self.singletons_.clear();
        self.address2id_.clear();
        self.count_ = 0;
    }
}