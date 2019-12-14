//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Sort.h"
#include <algorithm>
#include "../BlockMaker.h"

static BlockMaker<Sort> maker("sort");

Sort::Sort(std::vector<std::string> &args) {
    if (!args.empty()){
        throw std::runtime_error("Wrong arguments for command <sort>>!");
    }
}

std::vector<std::string> Sort::execute(std::vector<std::string>& data) {
    std::sort(data.begin(), data.end());
    return data;
}

COMMAND_TYPE Sort::get_command_type() const noexcept {
    return COMMAND_TYPE::PROCESSING;
}
