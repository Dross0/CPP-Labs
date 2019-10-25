//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK2_BLOCKMAKER_H
#define TASK2_BLOCKMAKER_H


#include "IBlockMaker.h"
#include "BlockFactory.h"


template <typename T>
class BlockMaker: public IBlockMaker {
public:
    explicit BlockMaker(const std::string& key){
        BlockFactory::instance().register_maker(key, this);
    }

    virtual IWorker * create(std::vector<std::string>& args){
        return new T(args);
    }
};


#endif //TASK2_BLOCKMAKER_H
