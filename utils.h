#ifndef TASK3_UTILS_H
#define TASK3_UTILS_H
#include <future>
#include "ThreadPool.h"

namespace task3 {
    template<typename T>
    std::vector<T> wait_for_all(std::vector<std::future<T>>& vf);
}

#endif //TASK3_UTILS_H
