#ifndef TASK3_SYNCQUEUE_H
#define TASK3_SYNCQUEUE_H
#include <mutex>
#include <condition_variable>
#include <list>
#include <chrono>

namespace task3 {

    template<typename T>
    class SyncQueue {
    public:
        void put(const T& val);
        void put(T&& val);
        bool get(T& val);
    private:
        std::mutex mtx;
        std::condition_variable cond;
        std::list<T> queue;
    };

}

#endif //TASK3_SYNCQUEUE_H
