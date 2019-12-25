//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Parser.h"
#include "Exceptions/wrong_command_order.h"
#include "Exceptions/cant_get_next_line.h"
#include "Exceptions/missed_end_of_command_block.h"
#include "Exceptions/missed_start_of_command_block.h"
#include "Exceptions/wrong_command_format.h"
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
        throw error::missed_start_of_command_block("Missed 'desc'");
    }
    while (getline(input_file_, str) && str != "csed"){
        size_t assigment_sign  = str.find('=');
        if (assigment_sign == std::string::npos){
            throw error::wrong_command_format("Wrong command format: '" + str + "'");
        }
        std::string cmd = str.substr(assigment_sign + 1);
        trim(cmd);
        if (cmd.empty()){
            throw error::wrong_command_format("Empty command");
        }
        id_table_[atoi((str.substr(0, assigment_sign - 1)).c_str())] = command_parse(cmd);
    }
    if (str != "csed"){
        throw error::missed_end_of_command_block("Missed 'csed' ");
    }
    if (!getline(input_file_, str)){
        throw error::cant_get_next_line("Cant read next line");
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
            throw error::wrong_command_order("Wrong command order line format");
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

void Parser::trim(std::string &str) const {
    size_t first_no_space = 0;
    size_t last_no_space = str.size() - 1;
    while (first_no_space < str.size() && isspace(str[first_no_space])){
        first_no_space++;
    }
    while (last_no_space >= 0 && isspace(str[last_no_space])){
        last_no_space--;
    }
    if (last_no_space <= first_no_space){
        str = "";
    }
    else if (first_no_space != 0) {
        str.erase(0, first_no_space);
    }
    else if (last_no_space != str.size() - 1) {
        str.erase(last_no_space + 1, str.size() - last_no_space);
    }
}
