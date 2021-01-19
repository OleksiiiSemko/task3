#include "FileAnalyzer.h"

SourceFileStatistic* FileAnalyzer::operator()(const std::string& path_to_file_) {
    path_to_file = path_to_file_;
    analyze_code();

    return &source_file_statistic;
}

void FileAnalyzer::analyze_code() {
    fs.open(path_to_file, std::ios_base::in);
    if (!fs) {
        //TODO: throw exception
    }
    source_file_statistic.path_to_file = path_to_file;
    for (std::string line; getline(fs, line);) {
        if (std::regex_search(line, one_line_comment_pat)) {
            source_file_statistic.commented_lines++;
        }
        else if (std::regex_search(line, multiline_comment_start_pat)) {
            count_multiline_comments(line);
        }
        else if (std::regex_search(line, blank_line)) {
            source_file_statistic.blank_lines++;
        }
        else if (!line.empty()) {
            source_file_statistic.code_lines++;
        }
    }

    fs.close();
}

void FileAnalyzer::count_multiline_comments(std::string& line) {
    while (!regex_search(line, multiline_comment_end_pat)) {
        source_file_statistic.commented_lines++;
        getline(fs, line);
    }
    source_file_statistic.commented_lines++;
}
