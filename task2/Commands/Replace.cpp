//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Replace.h"
#include <algorithm>

Replace::Replace(std::vector<std::string> &data, std::vector<std::string>& args) {
    if (args.size() != 2){
        throw new std::exception("Wrong arguments for command <replace>!")
    }
    data_ = data;
    old_word = args[0];
    new_word = args[1];
}

std::vector<std::string> Replace::execute() {
    size_t lines_amount = data_.size();
    for (size_t i = 0; i < lines_amount; ++i){
        std::replace(data_[i].begin(), data_[i].end(), old_word, new_word);
    }
    return data_;
}