//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Replace.h"
#include <algorithm>
#include <utility>


Replace::Replace(std::vector<std::string> &data, std::vector<std::string>& args) {
    if (args.size() != 2){
        throw std::runtime_error("Wrong arguments for command <grep>!");
    }
    data_ = std::move(data);
    old_word = args[0];
    new_word = args[1];
}

std::vector<std::string> Replace::execute() {
    size_t lines_amount = data_.size();
    for (size_t i = 0; i < lines_amount; ++i){
        size_t pos = 0;
        while ((pos = data_[i].find(old_word, pos)) != std::string::npos){
            data_[i].replace(pos, old_word.size(), new_word);
            pos += new_word.size();
        }
    }
    return data_;
}