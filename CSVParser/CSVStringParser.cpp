//
// Created by Андрей Гайдамака on 28.11.2019.
//

#include "CSVStringParser.h"

std::vector<std::string> CSVStringParser::parse(const std::string& str, char delimiter) {
    std::vector<std::string> list_of_strings;
    std::string tmp;
    for (char symbol : str){
        if (symbol == delimiter){
            list_of_strings.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += symbol;
    }
    if (!tmp.empty()){
        list_of_strings.push_back(tmp);
    }
    return list_of_strings;
}