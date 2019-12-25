//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "ReadFile.h"
#include "../BlockMaker.h"
#include "../Exceptions/wrong_arguments_amount.h"
#include "../Exceptions/cant_open_file.h"

static BlockMaker<ReadFile> maker("readfile");


ReadFile::ReadFile(std::vector<std::string>& args) {
    if (args.size() != 1){
        throw error::wrong_arguments_amount("Wrong arguments for command <fileread>!");
    }
    file_.open(args[0]);
    if (!file_.is_open()){
        throw error::cant_open_file("Cant open file " + args[0] + "!");
    }
}

ReadFile::~ReadFile(){
    file_.close();
}

std::vector<std::string> ReadFile::execute(std::vector<std::string>& data){
    std::vector<std::string> result;
    std::string str;
    while (getline(file_, str)){
        result.push_back(str);
    }
    return result;
}

COMMAND_TYPE ReadFile::get_command_type() const noexcept {
    return COMMAND_TYPE::INPUT;
}
