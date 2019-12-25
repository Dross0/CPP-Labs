//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "Workflow.h"
#include "Exceptions/first_command_is_not_input.h"
#include "Exceptions/last_command_is_not_output.h"
#include "Exceptions/middle_command_is_not_processing.h"

#include <utility>


Workflow::Workflow(std::string path) : path_(std::move(path))
{}

void Workflow::execute() {
    Parser par(path_);
    par.parse();
    std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > table = par.get_id_table();
    std::vector<unsigned int> cmd_order = par.get_commands_order();
    BlockFactory bf = BlockFactory::instance();
    size_t cmd_amount = cmd_order.size();
    std::vector<std::string> data;
    for (size_t i = 0; i < cmd_amount; ++i){
        ICommand * cmd = bf.create(table[cmd_order[i]].first, table[cmd_order[i]].second);
        if (i == 0 && cmd->get_command_type() != COMMAND_TYPE::INPUT){
            throw error::first_command_is_not_input("First command must be INPUT type");
        }
        else if (i == cmd_amount - 1 && cmd->get_command_type() != COMMAND_TYPE::OUTPUT){
            throw error::last_command_is_not_output("Last command must be OUTPUT type");
        }
        else if (i > 0 && i < (cmd_amount - 1) && cmd->get_command_type() != COMMAND_TYPE::PROCESSING){
            throw error::middle_command_is_not_processing("Middle command must be PROCESSING type");
        }
        data = cmd->execute(data);
        delete cmd;
    }
}