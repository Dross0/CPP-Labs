//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_BLOCKFACTORY_H
#define TASK2_BLOCKFACTORY_H
#include <vector>
#include <string>
#include <map>
#include "Commands/Dump.h"
#include "Commands/Grep.h"
#include "Commands/ReadFile.h"
#include "Commands/Sort.h"
#include "Commands/Replace.h"
#include "Commands/WriteFile.h"
#include "IBlockMaker.h"

class BlockFactory {
public:
    static BlockFactory& instance();
    IWorker * create(std::string& cmd, std::vector<std::string>& args) const;
    void register_maker(const std::string& key, IBlockMaker * maker);
private:
    std::map<std::string, IBlockMaker *> makers_;
};


#endif //TASK2_BLOCKFACTORY_H
