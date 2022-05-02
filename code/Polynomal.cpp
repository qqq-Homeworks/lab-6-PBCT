// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>

#include "Polynomal.hpp"


void Polynomal::SetOrder(bool order) {
    _order = order;
    if (order)
        _terms.sort(std::greater<>());
    else
        _terms.sort(std::less<>());
}

std::ostream &operator<<(ostream &out, const Polynomal &polynomal) {
    for (size_t i = 0; i < polynomal._terms.Size(); ++i) {
        out << polynomal._terms[i] << ' ';
    }
    return out;
}

Polynomal &Polynomal::operator+=(const Polynomal &polynomal) {

    for (size_t i = 0; i < polynomal._terms.Size(); ++i) {
        for (size_t j = 0; j < _terms.Size(); ++j) {
            if (polynomal._terms[i]._power == _terms[i]._power)
            {
                _terms[j] += polynomal._terms[i];
                break;
            }
        }
    }

    return *this;
}

Polynomal &Polynomal::operator*=(const Polynomal &) {


    return *this;

}

