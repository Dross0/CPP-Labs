//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK2_WORKFLOW_H
#define TASK2_WORKFLOW_H
#include <string>
#include <vector>
#include <map>
#include "Commands/ICommand.h"
#include "Parser.h"
#include "BlockFactory.h"


class Workflow {
public:
    explicit Workflow(std::string  path);

    void execute();
private:
    std::string path_;
};


#endif //TASK2_WORKFLOW_H
