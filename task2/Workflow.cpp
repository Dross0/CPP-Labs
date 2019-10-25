//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "Workflow.h"

#include <utility>


Workflow::Workflow(std::string path) : path_(std::move(path))
{}

void Workflow::execute() {
    Parser par(path_);
    par.parse();
    std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > table = par.get_id_table();
    std::vector<unsigned int> cmd_order = par.get_commands_order();
    BlockFactory bf = BlockFactory::instance();
    if (table[cmd_order[0]].first != "readfile"){
        throw std::runtime_error("First command is not <readfile>!");
    }
    size_t cmd_amount = cmd_order.size();
    if (table[cmd_order[cmd_amount - 1]].first != "writefile"){
        throw std::runtime_error("Last command is not <writefile>!");
    }
    std::vector<std::string> data;
    for (size_t i = 0; i < cmd_amount; ++i){
        if (i >= 1 && i < (cmd_amount - 1) && (table[cmd_order[i]].first == "writefile" || table[cmd_order[i]].first == "readfile")){
            throw std::runtime_error("<readfile> or <writefile> in the middle of commands order!");
        }
        IWorker * cmd = bf.create(table[cmd_order[i]].first, table[cmd_order[i]].second, data);
        data = cmd->execute();
    }
}