#include "AnalyzerFacade.h"

void task3::AnalyzerFacade::operator()() {
    for(auto& path:file_collector.source_files) {
        res.push_back(thread_pool.async([=]{
            file_analyzer(path);
        }));
    }
}