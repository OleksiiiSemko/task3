#include <iostream>
#include <cstring>
#include <thread>
#include "AnalyzerFacade.h"

int main(int args, char* argv[]) {
    std::string path;
    // Default path to the json file
    std::string json_path{boost::filesystem::current_path().string() + "/test.json"};
    int thread_numbers = std::thread::hardware_concurrency();
    if (args < 3) {
        std::cerr << "Please, provide --path parameter\n";
        return -1;
    }
    else {
        for (int i = 1; i <= (args+1) / 2; i+=2) {
            if (!strcmp(argv[i], "--path") || !strcmp(argv[i], "-p")) {
                path = argv[i+1];
            }
            else if (!strcmp(argv[i], "--json") || !strcmp(argv[i], "-j")) {
                json_path = argv[i+1];
            }
            else if (!strcmp(argv[i], "--threads") || !strcmp(argv[i], "-t")) {
                thread_numbers = std::atoi(argv[i+1]);
            }
            else {
                std::cerr << "Wrong parameter\n";
            }
        }
    }

    task3::AnalyzerFacade{path, json_path, thread_numbers}();

    return 0;
}
