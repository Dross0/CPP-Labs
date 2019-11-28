//
// Created by Андрей Гайдамака on 28.11.2019.
//

#include "CSVStringParser.h"

CSVStringParser::CSVStringParser(char delimiter) : delimiter_(delimiter)
{}

std::vector<std::string> CSVStringParser::parse(const std::string& str) {
    std::vector<std::string> list_of_strings;
    std::string tmp;
    for (char symbol : str){
        if (symbol == delimiter_){
            list_of_strings.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += symbol;
    }
    return list_of_strings;
}