cmake_minimum_required(VERSION 3.17)
project(task3)

add_subdirectory(Google_tests)
set(CMAKE_CXX_STANDARD 14)

# Add 'boost' libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.67.0 COMPONENTS filesystem)
find_package( Threads )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(task3
            FileCollector.cpp
            FileAnalyzer.cpp
            ThreadPool.cpp
            AnalyzerFacade.cpp
            JoinThreads.cpp
            SyncQueue.cpp
            Wrapper.cpp
            JsonParser.cpp
            main.cpp
            )
    target_link_libraries(task3 ${Boost_LIBRARIES})
    target_link_libraries(task3 ${CMAKE_THREAD_LIBS_INIT})
endif()