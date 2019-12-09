//
// Created by Андрей Гайдамака on 28.11.2019.
//

#ifndef TASK4_CSVSTRINGPARSER_H
#define TASK4_CSVSTRINGPARSER_H
#include <string>
#include <vector>

class CSVStringParser {
public:
    static std::vector<std::string> parse(const std::string& str, char delimiter = ',');
};


#endif //TASK4_CSVSTRINGPARSER_H
