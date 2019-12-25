//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Grep.h"
#include <utility>
#include "../BlockMaker.h"
#include "../Exceptions/wrong_arguments_amount.h"

static BlockMaker<Grep> maker("grep");


Grep::Grep(std::vector<std::string> &args) {
    if (args.size() != 1){
        throw error::wrong_arguments_amount("Wrong arguments for command <grep>!");
    }
    word_ = args[0];
}

std::vector<std::string> Grep::execute(std::vector<std::string>& data) {
    std::vector<std::string> res;
    size_t vect_size = data.size();
    for (size_t i = 0; i < vect_size; ++i){
        if (data[i].find(word_) != std::string::npos){
            res.push_back(data[i]);
        }
    }
    return res;
}

COMMAND_TYPE Grep::get_command_type() const noexcept {
    return COMMAND_TYPE::PROCESSING;
}
