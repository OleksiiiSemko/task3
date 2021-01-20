#ifndef TASK3_JSONPARSER_H
#define TASK3_JSONPARSER_H
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <fstream>
#include "FileAnalyzer.h"
#include <chrono>

namespace pt = boost::property_tree;

namespace task3 {
    class JsonParser {
    public:
        explicit JsonParser(const std::string& path_to_file)
        {
            fs.open(path_to_file, std::ofstream::out | std::ofstream::trunc);

            if (!fs) {
                //TODO: throw exception
            }
        }
        void parse();
        void operator()(std::vector<SourceFileStatistic*>& data_,
                std::chrono::high_resolution_clock::time_point start_) {
            data = std::move(data_);
            start = start_;
            parse();
        }

        ~JsonParser() {
            fs.close();
        }
    private:
        pt::ptree root;
        std::fstream fs;
        std::vector<SourceFileStatistic*> data;
        std::chrono::high_resolution_clock::time_point start;
    };
}


#endif //TASK3_JSONPARSER_H
