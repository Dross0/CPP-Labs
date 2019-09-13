#pragma once
#include <list>
#include <map>
#include <string>
#include <cctype>


class WordCounter{
public:
    WordCounter(std::list<std::string> list_of_strings_) : unique_words_(0), word_amount_(0)
    {
        count(list_of_strings_);
    }

    void print(){
        std::map<std::string, unsigned int>::iterator it;
        for (it = table_.begin(); it != table_.end(); it++){
            std::cout << it->first << " - " << it->second << std::endl;
        }
    }

    std::pair<std::string, unsigned int> getNextWord(){
        static std::map<std::string, unsigned int>::iterator it = table_.begin();
        std::pair<std::string, unsigned int> p;
        p.first = it->first;
        p.second = it->second;
        ++it;
        return p;
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

    WordCounter(WordCounter const & w){}

    void count(std::list<std::string> list_of_strings_){
        std::string word = "";
        for (std::string str: list_of_strings_){
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
            word = "";
        }
    }
};