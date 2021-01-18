cmake_minimum_required(VERSION 3.17)
project(task3)

add_subdirectory(Google_tests)
set(CMAKE_CXX_STANDARD 14)

add_executable(task3 main.cpp
        SyncQueue.cpp
        JoinThreads.cpp
        ThreadPool.cpp
        Wrapper.cpp
        AnalyzerFacade.cpp
        utils.cpp
        )