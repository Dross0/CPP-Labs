//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "Dump.h"
#include <stdexcept>
#include "../BlockMaker.h"
#include "../Exceptions/wrong_arguments_amount.h"
#include "../Exceptions/cant_open_file.h"

static BlockMaker<Dump> maker("dump");

Dump::Dump(std::vector<std::string> &args) {
    if (args.size() != 1){
        throw error::wrong_arguments_amount("Wrong arguments for command <dump>!");
    }
    file_.open(args[0]);
    if (!file_.is_open()){
        throw error::cant_open_file("Cant open file " + args[0] + "!");
    }
}

Dump::~Dump() {
    file_.close();
}

std::vector<std::string> Dump::execute(std::vector<std::string>& data) {
    size_t vect_size = data.size();
    for (size_t i = 0; i < vect_size; ++i) {
        file_ << data[i] << std::endl;
    }
    return data;
}

COMMAND_TYPE Dump::get_command_type() const noexcept {
    return COMMAND_TYPE::PROCESSING;
}
