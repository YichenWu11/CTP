#pragma once

#include "./function2/function2.hpp"
#include <vector>
#include <thread>
#include <future>
#include <queue>

namespace Chen {
    class ThreadPool {
    public:
        ThreadPool(size_t num);
        ~ThreadPool();

        // return std::future
        template<class F, class... Args>
        auto ReturnEnqueue(F&& f, Args&&... args);

        template<class F, class... Args>
        void Enqueue(F&& f, Args&&... args);

        void BasicEnqueue(fu2::unique_function<void()> task);

    private:
        std::vector<std::thread> workers;
        std::queue<fu2::unique_function<void()>> tasks;

        std::mutex mutex_tasks;
        std::condition_variable condition;
        bool stop{ false };
    };
}

#include "details/ThreadPool.inl"