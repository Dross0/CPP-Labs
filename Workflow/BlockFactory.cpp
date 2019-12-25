//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "BlockFactory.h"
#include "Exceptions/unrecognized_command.h"
#include "Exceptions/multiply_makers.h"
#include <stdexcept>

BlockFactory& BlockFactory::instance() {
    static BlockFactory factory;
    return factory;
}

ICommand * BlockFactory::create(std::string& cmd, std::vector<std::string>& args) const {
    auto obj = makers_.find(cmd);
    if (obj == makers_.end()) {
        throw error::unrecognized_command( "'"+ cmd  + "' is not a command");
    }
    IBlockMaker * maker = obj->second;
    return maker->create(args);
}

void BlockFactory::register_maker(const std::string& key, IBlockMaker * maker){
    if (makers_.find(key) != makers_.end()){
        throw error::multiply_makers("Multiply makers for '" + key + "'");
    }
    makers_[key] = maker;
}