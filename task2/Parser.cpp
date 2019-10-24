//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Parser.h"
#include <iostream>
#include <cstdlib>
#include <cctype>


Parser::Parser(const std::string & path){
    input_file_.open(path);
    if (!input_file_.is_open()){
        throw std::runtime_error("Cant open file " + path + "!");
    }
}

Parser::~Parser(){
    input_file_.close();
}



void Parser::parse(){
    std::string str;
    while (getline(input_file_, str) && str != "desc");
    if (str != "desc"){
        throw std::runtime_error("Wrong file structure");
    }
    while (getline(input_file_, str) && str != "csed"){
        size_t first_space  = str.find(' ');
        size_t second_space = str.find(' ', first_space + 1);
        if (first_space == std::string::npos || second_space == std::string::npos){
            throw std::runtime_error("Wrong string format!");
        }
        id_table_[atoi((str.substr(0, first_space)).c_str())] = command_parse(str.substr(second_space + 1));
    }
    if (!getline(input_file_, str)){
        throw std::runtime_error("Cant read next line!");
    }
    size_t str_size = str.size();
    std::string sub;
    for (size_t i = 0; i < str_size; ++i){
        if (str[i] == '-' || str[i] == '>') continue;
        if (isdigit(str[i])){
            sub += str[i];
        }
        else if (isspace(str[i])){
            if (!sub.empty())
                cmd_order.push_back(atoi(sub.c_str()));
            sub = "";
        }
        else{
            throw std::runtime_error("Wrong commands order!");
        }
    }
    if (!sub.empty()){
        cmd_order.push_back(atoi(sub.c_str()));
    }
}

std::pair<std::string, std::vector<std::string> > Parser::command_parse(const std::string & str){
    std::pair<std::string, std::vector<std::string> > cmd;
    std::string res;
    size_t str_size = str.size();
    bool was_cmd = false;
    for (size_t i = 0; i < str_size; ++i){
        if (isspace(str[i])){
            if (was_cmd){
                cmd.second.push_back(res);
            }
            else{
                cmd.first = (res);
                was_cmd = true;
            }
            res = "";
        }
        else{
            res += str[i];
        }
    }
    if (!res.empty()){
        if (was_cmd){
            cmd.second.push_back(res);
        }
        else{
            cmd.first = (res);
        }
    }
    return cmd;
}

std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > Parser::get_id_table() const{
    return id_table_;
}

std::vector<unsigned int> Parser::get_commands_order() const{
    return cmd_order;
}