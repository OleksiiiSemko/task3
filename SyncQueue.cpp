#include "SyncQueue.h"
#include <system_error>

template<typename T>
void task3::SyncQueue<T>::put(const T &val) {
    std::unique_lock<std::mutex> lck{mtx};
    queue.push_back(val);
    cond.notify_one();
}

template<typename T>
void task3::SyncQueue<T>::put(T &&val) {
    put(val);
}

template<typename T>
bool task3::SyncQueue<T>::get(T &val) {
    try {
        std::unique_lock<std::mutex> lck(mtx);
        val = queue.front();
        queue.pop_front();

        return true;
    }
    catch (...) {
        return false;
    }
}
