#ifndef TASK3_FILEANALYZER_H
#define TASK3_FILEANALYZER_H
#include <regex>
#include <fstream>

struct SourceFileStatistic {
    int blank_lines{0};
    int commented_lines{0};
    int code_lines{0};
    std::string path_to_file;
};

class FileAnalyzer {
public:
    FileAnalyzer() = default;
    void analyze_code();
    SourceFileStatistic* operator()(const std::string& path_to_file);

    SourceFileStatistic source_file_statistic;
private:
    void count_multiline_comments(std::string& line);
    std::string path_to_file;
    std::regex one_line_comment_pat {R"(^//)"};
    std::regex multiline_comment_start_pat {R"((\s)?[/]{1}[*]+)"};
    std::regex multiline_comment_end_pat {R"([*/]$)"};
    std::regex blank_line {R"(^$|^(\s)*$)"};
    std::fstream fs;
};

#endif //TASK3_FILEANALYZER_H
