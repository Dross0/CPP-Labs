//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "ReadFile.h"
#include "../BlockMaker.h"

static BlockMaker<ReadFile> maker("readfile");


ReadFile::ReadFile(std::vector<std::string>& args) {
    if (args.size() != 1){
        throw std::runtime_error("Wrong arguments for command <fileread>!");
    }
    file_.open(args[0]);
    if (!file_.is_open()){
        throw std::runtime_error("Cant open file " + args[0] + "!");
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