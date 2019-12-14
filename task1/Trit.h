//
// Created by Андрей Гайдамака on 24.09.2019.
//

#ifndef TASK1_TRIT_H
#define TASK1_TRIT_H
#include <cstdint>
#include <fstream>
#include <iostream>


enum class trit: uint8_t{
    UNKNOWN = 0,
    FALSE = 1,
    TRUE = 2
};

class Trit {
public:
    Trit();

    Trit(const Trit & t) = default;

    explicit Trit(bool value);

    explicit Trit(trit value);

    explicit Trit(int value);

    ~Trit() = default;

    Trit & operator=(const Trit & t);

    trit value() const;

    bool operator==(const Trit & t) const;

    bool operator==(const trit & t) const;

    bool operator==(const bool & t) const;

    bool operator!=(const Trit & t) const;

    bool operator!=(const trit & t) const;

    bool operator!=(const bool & t) const;

    Trit operator&(const Trit & t) const;

    Trit & operator&=(const Trit & t);

    Trit operator|(const Trit & t) const;

    Trit & operator|=(const Trit & t);

    Trit operator!() const;

    operator trit();

    operator int();

    operator bool();
private:
    trit value_;
};


std::ostream & operator<<(std::ostream & out, const Trit & t);


#endif //TASK1_TRIT_H
