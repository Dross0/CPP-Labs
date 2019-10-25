//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Grep.h"
#include <utility>



Grep::Grep(std::vector<std::string> &data, std::vector<std::string> &args) {
    if (args.size() != 1){
        throw std::runtime_error("Wrong arguments for command <grep>!");
    }
    data_ = std::move(data);
    word_ = args[0];
}

std::vector<std::string> Grep::execute() {
    std::vector<std::string> res;
    size_t vect_size = data_.size();
    for (size_t i = 0; i < vect_size; ++i){
        if (data_[i].find(word_) != std::string::npos){
            res.push_back(data_[i]);
        }
    }
    return res;
}