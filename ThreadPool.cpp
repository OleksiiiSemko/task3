#include "ThreadPool.h"

task3::ThreadPool::ThreadPool(const int threads_number) :
        done{false}, joiner{threads}
{
    try {
        for (int i = 0; i < threads_number; i++) {
            threads.push_back(
                    std::thread{&ThreadPool::worker_thread, this}
            );

        }
    }
    catch (...) {
        done = true;
        throw;
    }
}

void task3::ThreadPool::worker_thread() {
    while (!done) {
        Wrapper task;

        if (task_queue.get(task)) {
            task();
        }
        else {
            std::this_thread::yield(); // release thread if task hasn't been got
        }
    }
}

template<typename FunctionType>
std::future<typename std::result_of<FunctionType()>::type> task3::ThreadPool::async(FunctionType f) {
    typedef typename std::result_of<FunctionType()>::type
            result_type;
    std::packaged_task<result_type()> task{std::move(f)};
    std::future<result_type> res{task.get_future()};
    task_queue.put(std::move(task));
    return res;
}

task3::ThreadPool::~ThreadPool() {
    done = true;
}