#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "FileReader.hpp"
#include "WriterCsv.hpp"
#include "WordCounter.hpp"

bool comp(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b);

int main(int argc, char ** argv){
    if (argc != 3){
        return 1;
    }
    FileReader fr(argv[1]);
    std::list<std::string> list_of_strings;
    std::string str = fr.getLine();
    while(!str.empty()){
        list_of_strings.push_back(str);
        str = fr.getLine();
    }
    WordCounter wc(list_of_strings);
    std::vector<std::pair<std::string, unsigned int> > words_array;
    for (size_t i = 0; i < wc.getUniqueWordAmount(); ++i){
        words_array.push_back(wc.getNextWord());
    }
    std::sort(words_array.begin(), words_array.end(), comp);
    WriterCsv writer(argv[2]);
    writer.write("Word");
    writer.write("Amount");
    writer.writeln("Frequency");
    for (size_t i = 0; i < words_array.size(); ++i){
        writer.write(words_array[i].first);
        writer.write(std::to_string(words_array[i].second));
        writer.writeln(std::to_string(static_cast<double>(words_array[i].second) / wc.getWordAmount() * 100));
    }
    return 0;
}

bool comp(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b){
    return a.second > b.second;
}
