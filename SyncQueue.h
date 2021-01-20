#ifndef TASK3_SYNCQUEUE_H
#define TASK3_SYNCQUEUE_H
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

namespace task3 {

    template<typename T>
    class SyncQueue {
    public:
        SyncQueue() = default;
        SyncQueue(const SyncQueue<T>& other) {
            std::lock_guard<std::mutex> lck{other.mtx};
            queue = other.queue;
        }

        bool try_pop(T &value) {
            std::unique_lock<std::mutex> lck{mtx};
            if (queue.empty()) {
                return false;
            }
            value = std::move(queue.front());
            queue.pop();
            return true;
        }

        void push(T new_value) {
            std::unique_lock<std::mutex> lck{mtx};
            queue.push(std::move(new_value));
            cond.notify_one();
        }
    private:
        std::mutex mtx;
        std::condition_variable cond;
        std::queue<T> queue;
    };

}

#endif //TASK3_SYNCQUEUE_H
