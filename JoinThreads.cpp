//
// Created by oleksii on 1/18/21.
//

#include "JoinThreads.h"

inline task3::JoinThreads::~JoinThreads() {
    for (auto& thread:threads) {
        if(thread.joinable()) {
            thread.join();
        }
    }
}
