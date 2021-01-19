//
// Created by oleksii on 1/18/21.
//

#ifndef TASK3_ANALYZERFACADE_H
#define TASK3_ANALYZERFACADE_H
#include <vector>
#include <future>
#include "FileAnalyzer.h"
#include "ThreadPool.h"
#include "FileCollector.h"
#include "JsonParser.h"

namespace task3 {

    class AnalyzerFacade {
    public:
        AnalyzerFacade(const std::string& path_to_analyzed_folder, const std::string& path_to_save_folder,
                       int thread_numbers) :
                file_collector{path_to_analyzed_folder},
                json_parser{path_to_save_folder},
                thread_pool{thread_numbers}
        {};

        void operator()();

    private:
        std::vector<std::future<SourceFileStatistic*>> res;
        ThreadPool thread_pool;
        FileAnalyzer file_analyzer;
        FileCollector file_collector;
        JsonParser json_parser;
    };
}

#endif //TASK3_ANALYZERFACADE_H
