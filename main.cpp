#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

bool comp(pair<string, unsigned int> a, pair<string, unsigned int> b){
    return a.second > b.second;
}

class WordCounter{
public:
    explicit WordCounter(list<string> list_of_strings) : list_of_strings_(list_of_strings), word_amount_(0)
    {}

    void count(){
        const char * DELIMITERS = " \n\t.,-?!";
        for (string str: list_of_strings_){
            char * cstr = new char[str.length()];
            strcpy(cstr, str.c_str());
            char * cword = strtok(cstr, DELIMITERS);
            while(cword != NULL){
                string word(cword);
                if (table_.find(word) == table_.end()){
                    table_[word] = 0;
                }
                table_[word]++;
                word_amount_++;
                cword = strtok(NULL, DELIMITERS);
            }
        }
    }

    int write_to_csv(const string & path){
        ofstream file;
        file.open(path);
        if (!file.is_open())
            return 0;
        vector<pair<string, unsigned int>> l;
        for (auto it = table_.begin(); it != table_.end(); ++it){
            l.push_back(pair<string, unsigned int>(it->first, it->second));
        }
        sort(l.begin(), l.end(), comp);
        file << "Word,Amount,Frequency" << endl;
        for (auto it = l.begin(); it != l.end(); ++it) {
            file << it->first << "," << it->second << "," << (static_cast<double>(it->second) / word_amount_ * 100)
                 << endl;
        }
        file.close();
    }
private:
    list<string> list_of_strings_;
    unsigned int word_amount_;
    map<string, unsigned int> table_;

};

list<string>  get_string_list_from_file(ifstream & f){
    string str;
    list<string> lst;
    while (getline(f, str)){
        lst.push_back(str);
    }
    return lst;
}

int main(int argc, char ** argv) {
    if (argc != 3){
        return 1;
    }
    ifstream f(argv[1]);
    if (!f.is_open()){
        return 2;
    }
    list<string> l = get_string_list_from_file(f);
    WordCounter wc(l);
    wc.count();
    wc.write_to_csv(argv[2]);

    return 0;
}