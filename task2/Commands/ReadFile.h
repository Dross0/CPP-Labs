//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_READFILE_H
#define TASK2_READFILE_H

#include "IWorker.h"
#include <fstream>

class ReadFile : public IWorker {
public:
    explicit ReadFile(std::vector<std::string>& args);

    ~ReadFile() override ;

    std::vector<std::string> execute() override ;
private:
    std::ifstream file_;
};


#endif //TASK2_READFILE_H
