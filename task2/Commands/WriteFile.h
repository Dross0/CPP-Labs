//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_WRITEFILE_H
#define TASK2_WRITEFILE_H

#include "IWorker.h"
#include <fstream>

class WriteFile : public IWorker {
public:
    WriteFile(std::vector<std::string>& data, std::vector<std::string>& args);

    ~WriteFile() override ;

    std::vector<std::string> execute() override;
private:
    std::vector<std::string> data_;
    std::ofstream file_;
};


#endif //TASK2_WRITEFILE_H
