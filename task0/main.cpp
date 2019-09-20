#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "FileReader.hpp"
#include "WriterCsv.hpp"
#include "WordCounter.hpp"



int main(int argc, char ** argv){
    if (argc != 3){
        return 1;
    }
    FileReader fr(argv[1]);
    WordCounter wc;
    wc.read(fr);
    wc.write(argv[2]);
    return 0;
}


