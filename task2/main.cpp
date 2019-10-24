#include <iostream>
#include <stdexcept>
#include "Parser.h"
#include "BlockFactory.h"


int main(int argc, char ** argv) {
    if (argc != 2){
        throw std::invalid_argument("Wrong arguments amount!");
    }
    Parser par(argv[1]);
    par.parse();
    std::map<unsigned int, std::pair<std::string, std::vector<std::string> > > table = par.get_id_table();
    std::vector<unsigned int> cmd_order = par.get_commands_order();
    BlockFactory bf = BlockFactory::instance();
    if (table[cmd_order[0]].first != "readfile"){
        throw std::runtime_error("First command is not readfile!");
    }
    std::vector<std::string> data;
    size_t cmd_amount = cmd_order.size();
    for (size_t i = 0; i < cmd_amount; ++i){
        IWorker * cmd = bf.create(table[cmd_order[i]].first, table[cmd_order[i]].second, data);
        data = cmd->execute();
    }

    return 0;
}