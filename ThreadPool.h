#ifndef TASK3_THREADPOOL_H
#define TASK3_THREADPOOL_H
#include <thread>
#include <atomic>
#include <vector>
#include <thread>
#include <future>
#include "SyncQueue.h"
#include "Wrapper.h"
#include "JoinThreads.h"

namespace task3 {
    class ThreadPool {
    public:
        ThreadPool(const int threads_number);

        template<typename FunctionType>
        std::future<typename std::result_of<FunctionType()>::type>
                async(FunctionType f);
        ~ThreadPool();
    private:
        void worker_thread();
        std::atomic_bool done;
        SyncQueue<Wrapper> task_queue;
        std::vector<std::thread> threads;
        JoinThreads joiner;
    };
}

#endif //TASK3_THREADPOOL_H
