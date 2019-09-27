//
// Created by Андрей Гайдамака on 13.09.2019.
//

#ifndef TASK1_TRITSET_H
#define TASK1_TRITSET_H

#include <vector>
#include <stdint.h>
#include "Trit.h"


class TritSet {
public:
    explicit TritSet(const size_t size);

    TritSet(const TritSet & t);

    TritSet & operator=(const TritSet & t);

    static const uint8_t TRITS_IN_ONE_ELEMENT;

    class reference{
    public:
        reference(TritSet *d, size_t i);

        reference & operator=(const reference & r);

        reference & operator=(const Trit & t);

        void set_value(const Trit & t);

        Trit get_value() const;

        operator Trit();
    private:
        TritSet * data_;
        size_t ind_;
    };

    Trit operator[](size_t i) const;

    TritSet::reference operator[](size_t i);

    TritSet operator&(const TritSet & t) const;

    TritSet & operator&=(const TritSet & t);

    TritSet operator|(const TritSet & t) const;

    TritSet & operator|=(const TritSet & t);

    TritSet operator!() const;

    size_t capacity() const;

    size_t size() const;

    size_t length() const;

    void shrink();

    size_t cardinality() const;

    void trim(size_t last_index);
private:
    size_t size_;
    std::vector<uint32_t> set_;
};


#endif //TASK1_TRITSET_H
