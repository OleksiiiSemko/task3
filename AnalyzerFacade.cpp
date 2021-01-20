#include "AnalyzerFacade.h"
#include "utils.h"

void task3::AnalyzerFacade::operator()() {
    auto start = std::chrono::high_resolution_clock::now();
    ThreadPool thread_pool{thread_numbers};
    // Asynchronously analyze all files
    for (auto& path:file_collector.source_files) {
        res.push_back(thread_pool.async([=]{
            return FileAnalyzer()(path);
        }));
    }

    std::vector<SourceFileStatistic*> final_result = task3::wait_for_all(res);
    json_parser(final_result, start);
}
