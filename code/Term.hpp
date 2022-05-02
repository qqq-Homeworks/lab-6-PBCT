// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#ifndef CODE_TERM_HPP
#define CODE_TERM_HPP

#include <sstream>
#include <iostream>

class Polynomal;

class Term {
    int _coefficient = 0;
    size_t _power = 0;

    friend class Polynomal;

public:
    Term() = default;

    Term(int coeff) : _coefficient(coeff) {};

    Term(int coeff, size_t power) : _coefficient(coeff), _power(power) {};

    Term &operator+=(Term &term);

    friend std::ostream &operator<<(std::ostream &out, const Term &term);

    friend std::istream &operator>>(std::istream &in, Term &term);
};


Term operator+(Term &s1, Term &s2);


#endif //CODE_TERM_HPP
