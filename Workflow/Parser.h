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
    explicit Parser(const std::string & path);

    ~Parser();

    void parse();

    std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > get_id_table() const;

    std::vector<unsigned int> get_commands_order() const;
private:
    std::ifstream input_file_;
    std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > id_table_;
    std::vector<unsigned int> cmd_order;

    std::pair<std::string, std::vector<std::string> > command_parse(const std::string & str);
    void trim(std::string& str) const;
};

#endif //TASK2_PARSER_H
