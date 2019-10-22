#pragma once
#include <fstream>
#include <string>

class Parser{
public:    
    Parser(std::string path);
    
    Parser(std::ifstream input_file);
    
    std::string parse() const;
private:
    std::ifstream input_file_;    
};