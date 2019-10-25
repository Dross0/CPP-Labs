//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Dump.h"
#include <stdexcept>
#include <utility>



Dump::Dump(std::vector<std::string> &data, std::vector<std::string> &args) {
    if (args.size() != 1){
        throw std::runtime_error("Wrong arguments for command <dump>!");
    }
    data_ = std::move(data);
    file_.open(args[0]);
    if (!file_.is_open()){
        throw std::runtime_error("Cant open file " + args[0] + "!");
    }
}

Dump::~Dump() {
    file_.close();
}

std::vector<std::string> Dump::execute() {
    size_t vect_size = data_.size();
    for (size_t i = 0; i < vect_size; ++i){
        file_ << data_[i] << std::endl;
    }
    return data_;
}