#include "JsonParser.h"

void task3::JsonParser::parse() {
    for (auto& file_statistic : data) {
        pt::ptree stat;
        stat.put("commented_lines", file_statistic->commented_lines);
        stat.put("code_lines", file_statistic->code_lines);
        stat.put("blank_lines", file_statistic->blank_lines);
        root.add_child(pt::ptree::path_type(file_statistic->path_to_file, '|'),
                       stat);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    root.put("time", duration);
    pt::write_json(fs, root);
}
