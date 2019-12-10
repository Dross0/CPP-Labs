//
// Created by Андрей Гайдамака on 17.11.2019.
//

#ifndef TASK4_CSVPARSER_H
#define TASK4_CSVPARSER_H
#include <fstream>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include "CSVStringParser.h"
#include "TupleConverter.h"
#include "Exceptions/cant_open_file.h"
#include "Exceptions/cant_read_line.h"

template<class... Types>
class CSVParser {
    class iterator;
public:
    explicit CSVParser(const std::string & path, const unsigned int skip_lines = 0) : path_(path)
    {
        file_.open(path_);
        if (!file_.is_open()){
            error::cant_open_file err;
            err.set_file_name(path_.c_str());
            throw err;
        }
        for (size_t i = 0; i < skip_lines; ++i){
            get_next_line();
        }
    }

    iterator begin(){
        return iterator(this, 0);
    }

    iterator end(){
        return iterator(this, -1);
    }

    ~CSVParser(){
        file_.close();
    };

    CSVParser(const CSVParser& csv_parser) = delete;

    CSVParser& operator=(const CSVParser& csv_parser) = delete;
private:


    std::string path_;
    std::ifstream file_;

    std::string get_next_line(){
        std::string str;
        if (file_.eof()){
            error::cant_read_line err;
            err.set_file_name(path_.c_str());
            throw err;
        }
        getline(file_, str);
        return str;
    }

    class iterator{
    public:
        explicit iterator(CSVParser * cur, int file_line) : file_line_(file_line)
        {
            cur_obj_ = cur;
            pos_ = 0;
            if (file_line != -1)
                ++(*this);
        }

        std::tuple<Types...>& operator*(){
            return t_;
        }

        iterator& operator++(){
            if (file_line_ == -2){
                file_line_ = -1;
                return *this;
            }
            else if (file_line_ == -1){
                throw std::runtime_error("Cant it.end()++");
            }
            if (cur_obj_->file_.tellg() != pos_){
                cur_obj_->file_.clear();
                cur_obj_->file_.seekg(pos_, cur_obj_->file_.beg);
            }
            std::string str = cur_obj_->get_next_line();
            pos_ = cur_obj_->file_.tellg();
            ++file_line_;
            if (cur_obj_->file_.eof()){
                file_line_ = -2;
            }
            update_tuple(str);
            return *this;
        }

        iterator operator++(int){
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& it){
            return file_line_ == it.file_line_;
        }

        bool operator!=(const iterator& it){
            return !(*this == it);
        }
    private:
        int file_line_;
        std::tuple<Types...> t_;
        CSVParser * cur_obj_;
        fpos_t pos_;


        void update_tuple(const std::string& str){
            TupleConverter<Types...> converter(cur_obj_->path_, file_line_);
            converter.convert(t_, CSVStringParser::parse(str));
        }
    };

};


#endif //TASK4_CSVPARSER_H
