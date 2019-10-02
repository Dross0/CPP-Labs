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

TritSet::TritSet(const TritSet &t) : last_(t.last_), set_(t.set_)
{}

TritSet & TritSet::operator=(const TritSet &t){
    if (this != &t){
        last_ = t.last_;
        set_ = t.set_;
    }
    return *this;
}

Trit TritSet::operator[](size_t i) const{
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

TritSet::reference TritSet::operator[](size_t i){
    return TritSet::reference(this, i);
}

TritSet::reference::reference(TritSet *d, size_t i) : data_(d), ind_(i)
{}

void TritSet::reference::set_value(const Trit &t) {
    if (ind_ >= data_->capacity()){
        if (t == trit::UNKNOWN)
            return;
        data_->resize(ind_);
    }
    size_t index = ind_ / TRITS_IN_ONE_ELEMENT;
    uint32_t shift = 2 * (ind_ % TRITS_IN_ONE_ELEMENT);
    uint32_t mask = 0b11;
    data_->set_[index] &= ~(mask << shift);
    if (t == trit::TRUE)
        data_->set_[index] |= 0b10 << shift;
    else if (t == trit::FALSE)
        data_->set_[index] |= 0b01 << shift;
    else if (t == trit::UNKNOWN)
        data_->set_[index] |= 0b00 << shift;
    if (static_cast<long long>(ind_) > data_->last_ && t != trit::UNKNOWN)
        data_->last_ = ind_;
}

Trit TritSet::reference::get_value() const {
    if (data_->capacity() <= ind_)
        return Trit(trit::UNKNOWN);
    uint32_t value = data_->set_[ind_ / TRITS_IN_ONE_ELEMENT];
    value >>= 2 * (ind_ % TRITS_IN_ONE_ELEMENT);
    value &= 0b11;
    if (value == 0)
        return Trit(trit::UNKNOWN);
    else if (value == 1)
        return Trit(trit::FALSE);
    return Trit(trit::TRUE);
}

TritSet::reference & TritSet::reference::operator=(const Trit &t) {
    set_value(t);
    return *this;
}

TritSet::reference & TritSet::reference::operator=(const TritSet::reference &r) {
    set_value(r.get_value());
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
    if (nsize >= capacity()) {
        set_.resize(nsize / TRITS_IN_ONE_ELEMENT + (nsize % TRITS_IN_ONE_ELEMENT ? 1 : 0), 0);
    }
    else{
        set_.resize(nsize / TRITS_IN_ONE_ELEMENT + (nsize % TRITS_IN_ONE_ELEMENT ? 1 : 0));
    }
}

size_t TritSet::capacity() const {
    return set_.capacity() * TRITS_IN_ONE_ELEMENT;
}

size_t TritSet::size() const{
    return set_.size() * TRITS_IN_ONE_ELEMENT;
}

TritSet::reference::operator Trit(){
    return get_value();
}

size_t TritSet::length() const{
    return last_ + 1;
}

size_t TritSet::cardinality(const Trit & t) const {
    size_t amount = 0;
    for (size_t i = 0; i <= last_; ++i){
        //std::cout << (*this)[i] << std::endl;
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


