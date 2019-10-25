//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "BlockFactory.h"
#include <stdexcept>

BlockFactory& BlockFactory::instance() {
    static BlockFactory factory;
    return factory;
}

IWorker * BlockFactory::create(std::string& cmd, std::vector<std::string>& args) const {
    auto obj = makers_.find(cmd);
    if (obj == makers_.end()) {
        throw std::runtime_error("Unrecognized command!");
    }
    IBlockMaker * maker = obj->second;
    return maker->create(args);
}

void BlockFactory::register_maker(const std::string& key, IBlockMaker * maker){
    if (makers_.find(key) != makers_.end()){
        throw std::runtime_error("Multiple makers for given key!");
    }
    makers_[key] = maker;
}