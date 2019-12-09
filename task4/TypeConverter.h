//
// Created by Андрей Гайдамака on 09.12.2019.
//

#ifndef TASK4_TYPECONVERTER_H
#define TASK4_TYPECONVERTER_H
#include <string>
#include <sstream>


class TypeConverter{
public:
    template <class T>
    static bool convert(const std::string & str, T& x){
        std::istringstream iss(str);
        iss >> x;
        return iss.fail() || !iss.eof();
    }

    template <>
    static bool convert(const std::string & str, std::string& x){
        x = str;
        return false;
    }
};

#endif //TASK4_TYPECONVERTER_H
