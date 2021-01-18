#include "utils.h"

template<typename T>
std::vector<T> task3::wait_for_all(std::vector <std::future<T>> &vf) {
    std::vector<T> res;
    for (auto& fu : vf) {
        res.push_back(fu.get());
    }
    return res;
}
