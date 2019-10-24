//
// Created by Андрей Гайдамака on 22.10.2019.
//

#include "BlockFactory.h"
#include <stdexcept>

BlockFactory& BlockFactory::instance() {
    static BlockFactory factory;
    return factory;
}

IWorker * BlockFactory::create(std::string& cmd, std::vector<std::string>& args, std::vector<std::string>& data) const {
    if (cmd == "readfile") return new ReadFile(args);
    else if (cmd == "writefile") return new WriteFile(data, args);
    else if (cmd == "grep") return new Grep(data, args);
    else if (cmd == "sort") return new Sort(data, args);
    else if (cmd == "dump") return new Dump(data, args);
    else if (cmd == "replace") return new Replace(data, args);
    else throw std::runtime_error("Unrecognized command!");
}