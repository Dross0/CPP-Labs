//
// Created by Андрей Гайдамака on 21.11.2019.
//

#include "OptionParser.h"
#include <vector>
#include <string>
#include <iostream>

class Arg : public option::Arg{
public:
    static void print_error(const char* msg1, const option::Option& opt, const char* msg2)
    {
        std::cerr << msg1;
        std::cerr << opt.name << " " << opt.namelen;
        std::cerr << msg2;
    }

    static option::ArgStatus Required(const option::Option& option, bool msg){
        if (option.arg != nullptr){
            return option::ARG_OK;
        }
        if (msg){
            print_error("Unknown option ", option, "\n");
        }
        return option::ARG_ILLEGAL;
    }
};


const option::Descriptor usage[] =
        {
                {UNKNOWN, 0, "", "",option::Arg::None, "USAGE: example [options]\n\n""Options:" },
                {HELP, 0,"", "help",option::Arg::None, "  --help  \tPrint usage and exit." },
                {GAMER1, 0, "f", "first", Arg::Required, ""},
                {GAMER2, 0, "s", "second", Arg::Required, ""},
                {ROUNDS, 0, "c", "count", Arg::Required, ""},
                {0,0,0,0,0,0}
        };


Game_config  parse_arguments(int argc, char ** argv){
    argc -= (argc > 0);
    argv += (argc > 0);
    Game_config gf = {0, Gamer_type::RANDOM_GAMER, Gamer_type::RANDOM_GAMER};
    if (!argc){
        return gf;
    }
    option::Stats stats(usage, argc, argv);
    std::vector<option::Option> options(stats.options_max);
    std::vector<option::Option> buffer(stats.buffer_max);
    option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);
    if (parse.error())
        std::cout << "Error" << std::endl;
    if (options[HELP]) {
        option::printUsage(std::cout, usage);
    }
    else if (parse.optionsCount() <= 3){
        for (int i = 0; i < parse.optionsCount(); ++i){
            option::Option& opt = buffer[i];
            std::string arg = opt.arg;
            if (opt.index() == GAMER1){
                if (arg == "random"){
                    gf.gamer1 = Gamer_type::RANDOM_GAMER;
                }
                else if (arg == "optimal"){
                    gf.gamer1 = Gamer_type::OPTIMAL_GAMER;
                }
                else if (arg == "console"){
                    gf.gamer1 = Gamer_type::CONSOLE_GAMER;
                }
                else{
                    throw std::invalid_argument("Invalid argument: --first");
                }
            }
            else if (opt.index() == GAMER2){
                if (arg == "random"){
                    gf.gamer2 = Gamer_type::RANDOM_GAMER;
                }
                else if (arg == "optimal"){
                    gf.gamer2 = Gamer_type::OPTIMAL_GAMER;
                }
                else if (arg == "console"){
                    gf.gamer2 = Gamer_type::CONSOLE_GAMER;
                }
                else{
                    throw std::invalid_argument("Invalid argument: --second");
                }
            }
            else if (opt.index() == ROUNDS){
                gf.count = atoi(opt.arg);
                if (gf.count == 0){
                    throw std::invalid_argument("Invalid argument: --count");
                }
            }
            else{
                throw std::invalid_argument("Unknown argument");
            }
        }
    }
    else{
        throw std::runtime_error("Cant parse arguments");
    }
}