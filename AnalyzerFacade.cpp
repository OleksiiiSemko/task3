#include "AnalyzerFacade.h"
#include "utils.h"

void task3::AnalyzerFacade::operator()() {
    for(auto& path:file_collector.source_files) {
        res.push_back(thread_pool.async([=]{
            return file_analyzer(path);
        }));
    }

    std::vector<SourceFileStatistic*> final_result = task3::wait_for_all(res);
}