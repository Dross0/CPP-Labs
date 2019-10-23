//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_BLOCKFACTORY_H
#define TASK2_BLOCKFACTORY_H
#include <vector>
#include <string>
#include "Commands/include.h"

class BlockFactory {
public:
    static BlockFactory& instance();
    IWorker * create(std::string& cmd, std::vector<std::string>& args, std::vector<std::string>& data_) const;
};


#endif //TASK2_BLOCKFACTORY_H
