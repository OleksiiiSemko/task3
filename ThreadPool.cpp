#include "ThreadPool.h"

task3::ThreadPool::ThreadPool(int threads_number) :
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

        if (task_queue.try_pop(task)) {
            task();
        }
        else {
            std::this_thread::yield(); // release thread if task hasn't been got
        }
    }
}
