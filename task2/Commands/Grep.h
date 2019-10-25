//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_GREP_H
#define TASK2_GREP_H

#include "IWorker.h"

class Grep : public IWorker{
public:
    explicit Grep(std::vector<std::string>& args);

    std::vector<std::string> execute(std::vector<std::string>& data) override;
private:
    std::string word_;
};


#endif //TASK2_GREP_H
