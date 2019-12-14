//
// Created by Андрей Гайдамака on 13.09.2019.
//

#include "Tests/TritSet.h"

const uint8_t TritSet::TRITS_IN_ONE_ELEMENT = 16;

TritSet::TritSet(size_t size)
{
    last_ = -1;
    resize(size);
}

TritSet & TritSet::operator=(const TritSet &t){
    if (this != &t){
        last_ = t.last_;
        set_ = t.set_;
    }
    return *this;
}

Trit TritSet::operator[](size_t i) const{
    return get_value(i);
}

TritSet::reference TritSet::operator[](size_t i){
    return TritSet::reference(this, i);
}

TritSet::reference::reference(TritSet *d, size_t i) : data_(d), ind_(i)
{}

void TritSet::set_value(const Trit &t, size_t i) {
    if (i >= capacity()){
        if (t == trit::UNKNOWN)
            return;
        resize(i);
    }
    size_t index = i / TRITS_IN_ONE_ELEMENT;
    uint32_t shift = 2 * (i % TRITS_IN_ONE_ELEMENT);
    uint32_t mask = 0b11;
    set_[index] &= ~(mask << shift);
    if (t == trit::TRUE)
        set_[index] |= 0b10 << shift;
    else if (t == trit::FALSE)
        set_[index] |= 0b01 << shift;
    else if (t == trit::UNKNOWN)
        set_[index] |= 0b00 << shift;
    if (static_cast<long long>(i) >last_ && t != trit::UNKNOWN)
        last_ = i;
}

Trit TritSet::get_value(size_t i) const {
    if (capacity() <= i)
        return Trit(trit::UNKNOWN);
    uint32_t value = set_[i / TRITS_IN_ONE_ELEMENT];
    value >>= 2 * (i % TRITS_IN_ONE_ELEMENT);
    value &= 0b11;
    if (value == 0)
        return Trit(trit::UNKNOWN);
    else if (value == 1)
        return Trit(trit::FALSE);
    return Trit(trit::TRUE);
}

TritSet::reference & TritSet::reference::operator=(const Trit &t) {
    data_->set_value(t, ind_);
    return *this;
}

TritSet::reference & TritSet::reference::operator=(const TritSet::reference &r) {
    data_->set_value(r.data_->get_value(r.ind_), ind_);
    return *this;
}

TritSet & TritSet::operator&=(const TritSet & t){
    long long int len = t.length();
    if (len > set_.size()){
        resize(len);
    }
    for (size_t i = 0; i < len; ++i){
        (*this)[i] = Trit((*this)[i]) & Trit(t[i]);
    }
    for (size_t i = len; i <= last_; ++i){
        (*this)[i] = Trit(trit::UNKNOWN);
    }
    return *this;
}

TritSet TritSet::operator&(const TritSet & t) const{
    TritSet tmp = TritSet(*this);
    tmp &= t;
    return tmp;
}

TritSet & TritSet::operator|=(const TritSet & t){
    long long int len = t.length();
    if (len >= set_.size()){
        resize(len);
    }
    for (size_t i = 0; i < len; ++i){
        ((*this)[i]) = Trit((*this)[i]) | Trit(t[i]);
    }
    for (size_t i = len; i <= last_; ++i){
        ((*this)[i]) = Trit(trit::UNKNOWN);
    }
    return *this;
}

TritSet TritSet::operator|(const TritSet & t) const{
    TritSet tmp = TritSet(*this);
    tmp |= t;
    return tmp;
}

TritSet TritSet::operator~() const{
    TritSet arr = TritSet(*this);
    for (size_t i = 0; i <= last_; ++i){
        (*this)[i] = !Trit((*this)[i]);
    }
    return arr;
}

void TritSet::resize(size_t nsize){
    set_.resize(nsize / TRITS_IN_ONE_ELEMENT + (nsize % TRITS_IN_ONE_ELEMENT ? 1 : 0), 0);
}

size_t TritSet::capacity() const {
    return set_.capacity() * TRITS_IN_ONE_ELEMENT;
}

size_t TritSet::size() const{
    return set_.size() * TRITS_IN_ONE_ELEMENT;
}

TritSet::reference::operator Trit(){
    return data_->get_value(ind_);
}

size_t TritSet::length() const{
    return last_ + 1;
}

size_t TritSet::cardinality(const Trit & t) const {
    size_t amount = 0;
    for (size_t i = 0; i <= last_; ++i){
        if ((*this)[i] == t){
            amount++;
        }
    }
    return amount;
}

void TritSet::shrink() {
    resize(last_);
}

void TritSet::trim(size_t last_index){
    size_t cap = capacity();
    for (size_t i = last_index + 1; i < cap; ++i){
        (*this)[i] = Trit(trit::UNKNOWN);
    }
    last_ = last_index;
}


