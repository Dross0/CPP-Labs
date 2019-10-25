//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_REPLACE_H
#define TASK2_REPLACE_H

#include "IWorker.h"

class Replace : public IWorker {
public:
    explicit Replace(std::vector<std::string>& args);

    std::vector<std::string> execute(std::vector<std::string>& data) override;
private:
    std::string old_word;
    std::string new_word;
};


#endif //TASK2_REPLACE_H
