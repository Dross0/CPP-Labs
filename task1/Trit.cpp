//
// Created by Андрей Гайдамака on 24.09.2019.
//

#include "Trit.h"

Trit::Trit() : value_(trit::UNKNOWN)
{}

Trit::Trit(const bool value){
    if (value)
        value_ = trit::TRUE;
    else
        value_ = trit::FALSE;
}

Trit::Trit(const trit value) : value_(value)
{}

Trit::Trit(const int value){
    if (value > 0)
        value_ = trit::TRUE;
    else if (value == 0)
        value_ = trit::UNKNOWN;
    else
        value_ = trit::FALSE;
}

Trit::~Trit() {}

Trit & Trit::operator=(const Trit & t){
    value_ = t.value_;
    return *this;
}

trit Trit::value() const{
    return value_;
}

bool Trit::operator==(const Trit &t) const {
    return value_ == t.value_;
}

bool Trit::operator==(const trit &t) const {
    return value_ == t;
}

bool Trit::operator==(const bool & t) const{
    if (t)
        return value_ == trit::TRUE;
    else
        return value_ == trit::FALSE;
}

bool Trit::operator!=(const Trit & t) const{
    return !((*this) == t);
}

bool Trit::operator!=(const trit & t) const{
    return !((*this) == t);
}

bool Trit::operator!=(const bool & t) const{
    return !((*this) == t);
}

Trit Trit::operator&(const Trit & t) const{
    std::cout << "1: "<< *this << " 2: " << t << std::endl;
    if (value_ == trit::FALSE || t.value_ == trit::FALSE)
        return Trit(trit::FALSE);
    if (value_ == trit::UNKNOWN || t.value_ == trit::UNKNOWN)
        return Trit(trit::UNKNOWN);
    return Trit(trit::TRUE);

}

Trit & Trit::operator&=(const Trit & t){
    *this = (*this) & t;
    return *this;
}

Trit Trit::operator|(const Trit & t) const{
    if (value_ == trit::TRUE || t.value_ == trit::TRUE)
        return Trit(trit::TRUE);
    if (value_ == trit::UNKNOWN || t.value_ == trit::UNKNOWN)
        return Trit(trit::UNKNOWN);
    return Trit(trit::FALSE);
}

Trit & Trit::operator|=(const Trit & t){
    *this = (*this) | t;
    return *this;
}

Trit Trit::operator!() const{
    if (value_ == trit::FALSE)
        return Trit(trit::TRUE);
    else if (value_ == trit::TRUE)
        return Trit(trit::FALSE);
    return Trit(trit::UNKNOWN);
}

Trit::operator trit(){
    return value_;
}

Trit::operator int(){
    if (value_ == trit::TRUE)
        return 1;
    else if (value_ == trit::UNKNOWN)
        return 0;
    return -1;
}

Trit::operator bool(){
    return value_ == trit::TRUE;
}

std::ostream & operator<<(std::ostream & out, const Trit & t){
    trit val = t.value();
    if (val == trit::TRUE)
        out << "TRUE";
    else if (val == trit::UNKNOWN)
        out << "UNKNOWN";
    else if (val == trit::FALSE)
        out << "FALSE";
    return out;
}