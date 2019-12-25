#include <iostream>
#include "TupleOutput.h"
#include "CSVStringParser.h"
#include "CSVParser.h"


int main() {
    CSVParser<std::string, int, double> csv_parser("in.csv");
    for (auto &it: csv_parser){
        std::cout << it << std::endl;
    }
    return 0;
}