//
// Created by Андрей Гайдамака on 13.09.2019.
//

#ifndef TASK1_TRITSET_H
#define TASK1_TRITSET_H

#include <vector>
#include <stdint.h>
#include "../Trit.h"


class TritSet {
public:
    explicit TritSet(size_t size = 0);

    TritSet(const TritSet & t) = default;

    TritSet & operator=(const TritSet & t);

    static const uint8_t TRITS_IN_ONE_ELEMENT;

    class reference{
    public:
        reference(TritSet *d, size_t i);

        reference & operator=(const reference & r);

        reference & operator=(const Trit & t);

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

    TritSet operator~() const;

    size_t capacity() const;

    size_t size() const;

    size_t length() const;

    void shrink();

    size_t cardinality(const Trit & t) const;

    void trim(size_t last_index);

    void resize(size_t nsize);
private:
    long long last_;
    std::vector<uint32_t> set_;

    void set_value(const Trit & t, size_t i);

    Trit get_value(size_t i) const;
};


#endif //TASK1_TRITSET_H
