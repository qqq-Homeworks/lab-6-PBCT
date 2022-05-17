// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_POLYNOMAL_HPP
#define CODE_POLYNOMAL_HPP


#include "MyVector.hpp"
#include "Term.hpp"

class Polynomal {
    MyVector<Term> _terms = {};
    size_t _maxpower = 0;

public:
    Polynomal() = default;

    Polynomal(int c, size_t power = 0) : _terms(Term(c, power)) {};

    Polynomal(Term term) : _maxpower(term._power) {
        for (size_t i = 0; i < term._power; ++i) {
            _terms.add_element(Term(0, i));
        }
        _terms.add_element(term);
    };

    Polynomal(size_t power) : _maxpower(power) {
        for (size_t i = 0; i < power+1; ++i) {
            _terms.add_element(Term(0, i));
        }
    };

    Polynomal(const Polynomal &poly) : _maxpower(poly._maxpower), _terms(poly._terms) {};

    Polynomal &operator=(const Polynomal &poly) = default;

    Polynomal &operator+=(const Polynomal &);
    Polynomal &operator+=(const Term &);

    Polynomal &operator*=(const Polynomal &);

    friend std::ostream &operator<<(std::ostream &out, const Polynomal &polynomal);

    friend std::istream &operator>>(std::istream &in, Polynomal &polynomal);
};

Polynomal operator+(Polynomal, Polynomal);

Polynomal operator*(Polynomal, Polynomal);


#endif //CODE_POLYNOMAL_HPP
