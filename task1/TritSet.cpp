//
// Created by Андрей Гайдамака on 13.09.2019.
//

#include "TritSet.h"

const uint8_t TritSet::TRITS_IN_ONE_ELEMENT = 16;

TritSet::TritSet(const size_t size) : size_(size)
{
    set_.resize(size);
    set_.assign(size, 0);
}

TritSet::TritSet(const TritSet &t) : size_(t.size_), set_(t.set_)
{}

TritSet & TritSet::operator=(const TritSet &t){
    if (this != &t){
        size_ = t.size_;
        set_ = t.set_;
    }
    return *this;
}

Trit TritSet::operator[](size_t i) const{
    if (set_.capacity() * TritSet::TRITS_IN_ONE_ELEMENT > i)
        return Trit(trit::UNKNOWN);
    size_t index = i / TritSet::TRITS_IN_ONE_ELEMENT + (i % TritSet::TRITS_IN_ONE_ELEMENT ? 1 : 0);
    uint8_t bit_index = (i - (i / TritSet::TRITS_IN_ONE_ELEMENT) * TritSet::TRITS_IN_ONE_ELEMENT) * 2;
    const uint8_t MASK = 0b11;
    uint8_t value = (set_[index] >> (bit_index - 2)) & MASK;
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
    size_t index = ind_ / TritSet::TRITS_IN_ONE_ELEMENT + (ind_ % TritSet::TRITS_IN_ONE_ELEMENT ? 1 : 0);
    uint8_t bit_index = (ind_ - (ind_ / TritSet::TRITS_IN_ONE_ELEMENT) * TritSet::TRITS_IN_ONE_ELEMENT) * 2;
    uint8_t mask = 255;

}

Trit TritSet::reference::get_value() const {

}

TritSet::reference & TritSet::reference::operator=(const Trit &t) {
    set_value(t);
    return *this;
}

TritSet::reference & TritSet::reference::operator=(const TritSet::reference &r) {
    set_value(r.get_value());
    return *this;
}

