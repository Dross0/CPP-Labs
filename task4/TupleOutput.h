//
// Created by Андрей Гайдамака on 22.11.2019.
//

#ifndef TASK4_TUPLEOUTPUT_H
#define TASK4_TUPLEOUTPUT_H
#include <iostream>
#include <tuple>


template <class Ch, class Tr, int Index, class ...Args>
struct Print {
    static void print_tuple_element(std::basic_ostream<Ch, Tr> &os, std::tuple<Args...> const &t) {
        auto elem = std::get<Index>(t);
        Print< Ch, Tr, Index - 1, Args...>::print_tuple_element(os, t);
        os << elem;
        if (Index != sizeof...(Args) - 1){
            os << ", ";
        }
    }
};

template <class Ch, class Tr, class ...Args>
struct Print<Ch, Tr, -1, Args...>{
    static void print_tuple_element(std::basic_ostream<Ch, Tr> &os, std::tuple<Args...> const &t) {
        return;
    }
};


template<class Ch, class Tr, class ...Args>
std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t){
    Print<Ch, Tr, sizeof...(Args) - 1, Args...>::print_tuple_element(os, t);
    return os;
}


#endif //TASK4_TUPLEOUTPUT_H
