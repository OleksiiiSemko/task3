#ifndef TASK3_JOINTHREADS_H
#define TASK3_JOINTHREADS_H
#include <vector>
#include <thread>

namespace task3 {

    class JoinThreads {
    public:
        explicit JoinThreads(std::vector<std::thread>& threads_) :
                threads{threads_}
        {};
        ~JoinThreads();

    private:
        std::vector<std::thread>& threads;
    };
}

#endif //TASK3_JOINTHREADS_H
