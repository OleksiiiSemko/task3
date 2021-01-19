#include "SyncQueue.h"
#include <system_error>

template<typename T>
task3::SyncQueue<T>::SyncQueue(const SyncQueue<T>& other) {
    std::lock_guard<std::mutex> lck{other.mtx};
    queue = other.queue;
}

template<typename T>
void task3::SyncQueue<T>::wait_and_pop(T &value) {
    std::unique_lock<std::mutex> lck(mtx);
    cond.wait(lck, [this]{ return !queue.empty(); });
    value = queue.front();
    queue.pop();
}

template<typename T>
std::shared_ptr<T> task3::SyncQueue<T>::wait_and_pop() {
    std::unique_lock<std::mutex> lck{mtx};
    cond.wait(lck, [this]{ return !queue.empty(); });
    std::shared_ptr<T> res{std::make_shared<T>(queue.front())};
    queue.pop();
    return res;
}


template<typename T>
std::shared_ptr<T> task3::SyncQueue<T>::try_pop() {
    std::lock_guard<std::mutex> lck{mtx};
    if (queue.empty()) {
        return std::shared_ptr<T>{};
    }
    std::shared_ptr<T> res{std::make_shared<T>(queue.front())};
    queue.pop();
    return res;
}