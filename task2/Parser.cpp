//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Parser.h"
#include <iostream>
#include <cstdlib>
#include <cctype>


Parser::Parser(std::string path){
    input_file_.open(path);
    if (!input_file_.is_open()){
        throw new std::exception("Cant open " + path);
    }
}

Parser::~Parser(){
    input_file_.close();
}



void Parser::parse(){
    std::string str = "";
    while (getline(input_file_, str) && str != "desc");
    if (str != "desc"){
        //throw new std::exception("Wrong file structure");
    }
    while (getline(input_file_, str) && str != "csed"){
        size_t first_space  = str.find(' ');
        size_t second_space = str.find(' ', first_space + 1);
        if (first_space == std::string::npos || second_space == std::string::npos){
            throw new std::exception("Wrong string format!");
        }
        id_table_[atoi((str.substr(0, first_space)).c_str())] = command_parse(str.substr(second_space + 1));
    }
    if (getline(input_file_, str)){
        throw new std::exception("Cant read next line!");
    }
    size_t str_size = str.size();
    std::string sub = "";
    for (size_t i = 0; i < str_size; ++i){
        if (str[i] == '-' || str[i] == '>') continue;
        if (isdigit(str[i])){
            sub += str[i];
        }
        else if (isspace(str[i])){                    //Can be wrong with \n
            cmd_order.push_back(atoi(sub.c_str()));
            sub = "";
        }
        else{
            throw new std::exception("Wrong commands order!");
        }
    }
}

std::pair<std::string, std::vector<std::string> > Parser::command_parse(const std::string & str){
    std::pair<std::string, std::vector<std::string> > cmd;
    std::string res = "";
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
    return cmd;
}