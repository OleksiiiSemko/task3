#include <gtest/gtest.h>
#include "../FileCollector.h"
#include "../FileAnalyzer.h"
#include "../AnalyzerFacade.h"

TEST (FileCollector, TestCollecting) {
    int vector_size{3};
    FileCollector file_collector{"/home/oleksii/Documents/SofServe/task3/test_files"};
    ASSERT_EQ(file_collector.source_files.size(), vector_size);
}

TEST (FileAnalyzer, TestAnalizing) {
    int commented_lines{5};
    int code_lines{4};
    int blank_lines{3};

    FileAnalyzer<SourceFileStatistic> file_analyzer;
    SourceFileStatistic *statistic = file_analyzer("/home/oleksii/Documents/SofServe/task3/test_files/test1.cpp");

    ASSERT_EQ(statistic->commented_lines, commented_lines);
    ASSERT_EQ(statistic->code_lines, code_lines);
    ASSERT_EQ(statistic->blank_lines, blank_lines);

    task3::AnalyzerFacade("/home/oleksii/Documents/SofServe/task3/test_files/test1.cpp", 4)();
}
