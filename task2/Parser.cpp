#include <Parser.h>

Parser::Parser(std::string path){
        input_file.open(path);
        if (!input_file.is_open()){
            throw new exception("Cant open " + path);
        }
    }
    
Parser::Parser(std::ifstream input_file) : input_file_(input_file)
{}
    
std::string Parser::parse() const{
    
} 