#pragma once
#include <list>
#include <map>
#include <string>
#include <cctype>
#include "FileReader.hpp"
#include "WriterCsv.hpp"

bool comp(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b){
    return a.second > b.second;
}

class WordCounter{
public:
    WordCounter() : unique_words_(0), word_amount_(0)
    {}

    void read(FileReader & fr){
        std::string str;
        while (fr.getLine(str)){
            count(str);
        }
    }

    void read(std::string  path){
        FileReader fr(path);
        std::string str;
        if (fr.is_open()){
            while (fr.getLine(str)){
                count(str);
            } 
        }
    }

    void write(std::string path){
        WriterCsv writer(path);
        std::vector<std::pair<std::string, unsigned int> > words_array;
        for (std::map<std::string, unsigned int>::iterator it = table_.begin(); it != table_.end(); ++it){
            std::pair<std::string, unsigned int> p;
            p.first = it->first;
            p.second = it->second;
            words_array.push_back(p);
        }
        std::sort(words_array.begin(), words_array.end(), comp);
        writer.write("Word");
        writer.write("Amount");
        writer.writeln("Frequency");
        for (size_t i = 0; i < words_array.size(); ++i){
            writer.write(words_array[i].first);
            writer.write(std::to_string(words_array[i].second));
            writer.writeln(std::to_string(static_cast<double>(words_array[i].second) / word_amount_ * 100));
        }
    }



    unsigned int getWordAmount() const{
        return word_amount_;
    }

    unsigned int getUniqueWordAmount() const{
        return unique_words_;
    }

private:
    unsigned int unique_words_;
    unsigned int word_amount_;
    std::map<std::string, unsigned int> table_;

    WordCounter(WordCounter const & w){};

    void count(std::string str){
        std::string word = "";
        for (size_t i = 0; i <= str.length(); ++i){
            if (isalnum(str[i])){
                word += str[i];
            }
            else if (!word.empty()){
                if (table_.find(word) == table_.end()){
                    table_[word] = 0;
                    unique_words_++;
                }
                table_[word]++;
                word_amount_++;
                word = "";
            }
        }
    }
};