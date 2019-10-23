//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_PARSER_H
#define TASK2_PARSER_H

#include <fstream>
#include <string>
#include <map>
#include <vector>


class Parser{
public:
    Parser(std::string path);

    ~Parser();

    void parse();
private:
    std::ifstream input_file_;
    std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > id_table_;
    std::vector<unsigned int> cmd_order;

    std::pair<std::string, std::vector<std::string> > command_parse(const std::string & str);
};

#endif //TASK2_PARSER_H
