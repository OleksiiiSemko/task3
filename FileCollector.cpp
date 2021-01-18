#include "FileCollector.h"
#include <iostream>

FileCollector::FileCollector(const std::string& path_to_folder) {
    collect_files(path_to_folder);
}

void FileCollector::collect_files(const std::string& path_to_folder) {
    if (!fs::exists(path_to_folder)) {
    }
    _find_files(path_to_folder);
}

void FileCollector::_find_files(const std::string& path_to_folder) {
    if (fs::is_directory(path_to_folder)) {
        fs::directory_iterator end_iter;
        for (fs::directory_iterator dir_iter(path_to_folder);
             dir_iter != end_iter;
             ++dir_iter) {
            _match_file(dir_iter);
        }
    }
}

void FileCollector::_match_file(fs::directory_iterator dir_iter) {
    try {
        if (fs::is_directory(dir_iter -> status())) {
            _find_files(dir_iter -> path().string());
        }
        else if (fs::is_regular_file(dir_iter -> status())) {
            if (std::regex_search(dir_iter -> path().string(),
                             _source_files_pat
                             )) {
                source_files.push_back(dir_iter -> path().string());
            }
        }
    }
    catch (const std::exception& ex) {
        std::cout << dir_iter -> path().filename() << " " << ex.what() << std::endl;
    }
}
