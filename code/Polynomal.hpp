// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_POLYNOMAL_HPP
#define CODE_POLYNOMAL_HPP


#include "MyVector.hpp"
#include "Term.hpp"

class Polynomal {
    MyVector<Term> _terms = {Term()};
    size_t _maxpower = 0;
    bool _order = 0;

public:
    Polynomal() = default;

    Polynomal(int c, size_t power = 0) : _terms(Term(c, power)) {};

    Polynomal(Term term) : _maxpower(term._power), _terms(term) {};

    Polynomal(const Polynomal &poly) : _maxpower(poly._maxpower), _order(poly._order), _terms(poly._terms) {};

    Polynomal &operator=(const Polynomal &poly) {
        _maxpower = poly._maxpower;
        _order = poly._order;
        _terms = poly._terms;

        return *this;
    };

    inline void SetOrder(bool);

    Polynomal &operator+=(const Polynomal &);

    Polynomal &operator*=(const Polynomal &);

    friend std::ostream &operator<<(std::ostream &out, const Polynomal &polynomal);

};


#endif //CODE_POLYNOMAL_HPP
