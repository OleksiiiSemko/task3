#ifndef TASK3_FILECOLLECTOR_H
#define TASK3_FILECOLLECTOR_H
#include <vector>
#include <string>
#include <regex>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class FileCollector {
public:
    FileCollector(const std::string& path_to_folder);
    void collect_files(const std::string& path_to_folder);

    std::vector<std::string> source_files;
private:
    void _find_files(const std::string& path_to_folder);
    void _match_file(fs::directory_iterator dir_iter);
    std::regex _source_files_pat{R"(.h$|.hpp$|.c$|.cpp$)"};
};


#endif //TASK3_FILECOLLECTOR_H
