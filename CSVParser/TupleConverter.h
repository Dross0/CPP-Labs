//
// Created by Андрей Гайдамака on 09.12.2019.
//

#ifndef TASK4_TUPLECONVERTER_H
#define TASK4_TUPLECONVERTER_H
#include "TypeConverter.h"
#include "Exceptions/cant_convert.h"
#include "Exceptions/too_few_columns.h"
#include "Exceptions/too_many_columns.h"
#include <vector>

template <class ...Args>
class TupleConverter {
public:
    TupleConverter(const std::string& file_name, unsigned int file_line) : file_name_(file_name), file_line_(file_line)
    {}

    void convert(std::tuple<Args...> & t, const std::vector<std::string>& data){
        if (data.size() > sizeof...(Args)){
            error::too_many_columns err;
            err.set_file_name(file_name_.c_str());
            err.set_file_line(file_line_);
            throw err;
        }
        else if (data.size() < sizeof...(Args)){
            error::too_few_columns err;
            err.set_file_name(file_name_.c_str());
            err.set_file_line(file_line_);
            throw err;
        }
        parse<0, Args...>(t, data);
    }
private:
    const std::string & file_name_;
    unsigned int file_line_;

    template <size_t Index, class T, class ...Others>
    void parse(std::tuple<Args...>& t, const std::vector<std::string>& data){
        T x;
        bool fail = TypeConverter::convert<T>(data[Index], x);
        if (fail){
            error::cant_convert err;
            err.set_file_name(file_name_.c_str());
            err.set_file_line(file_line_);
            err.set_column_content(data[Index].c_str());
            throw err;
        }
        std::get<Index>(t) = x;
        parse<Index+1, Others...>(t, data);
    }

    template <size_t Index>
    void parse(std::tuple<Args...>& t, const std::vector<std::string>& data){}
};


#endif //TASK4_TUPLECONVERTER_H
