//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Replace.h"
#include <algorithm>
#include <utility>
#include "../BlockMaker.h"
#include "../Exceptions/wrong_arguments_amount.h"

static BlockMaker<Replace> maker("replace");


Replace::Replace(std::vector<std::string>& args) {
    if (args.size() != 2){
        throw error::wrong_arguments_amount("Wrong arguments for command <grep>!");
    }
    old_word = args[0];
    new_word = args[1];
}

std::vector<std::string> Replace::execute(std::vector<std::string>& data) {
    size_t lines_amount = data.size();
    for (size_t i = 0; i < lines_amount; ++i){
        size_t pos = 0;
        while ((pos = data[i].find(old_word, pos)) != std::string::npos){
            data[i].replace(pos, old_word.size(), new_word);
            pos += new_word.size();
        }
    }
    return data;
}

COMMAND_TYPE Replace::get_command_type() const noexcept {
    return COMMAND_TYPE::PROCESSING;
}
