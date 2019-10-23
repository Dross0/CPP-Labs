#include <iostream>
#include <stdexcept>
#include "Parser.h"


int main(int argc, char ** argv) {
    if (argc != 2){
        throw std::invalid_argument("Wrong arguments amount!");
    }
    Parser par(argv[1]);
    return 0;
}