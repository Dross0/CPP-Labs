//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_DUMP_H
#define TASK2_DUMP_H

#include "IWorker.h"
#include <fstream>

class Dump : public IWorker {
public:
    Dump(std::vector<std::string>& data, std::vector<std::string>& args);

    ~Dump() override ;

    std::vector<std::string> execute() override ;
private:
    std::ofstream file_;
    std::vector<std::string> data_;
};


#endif //TASK2_DUMP_H
