// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>

#include "Polynomal.hpp"

std::ostream &operator<<(std::ostream &out, const Polynomal &polynomal) {
    size_t q = 0;
    bool isNull = true;

    for (size_t i = 0; i < polynomal._maxpower + 1; ++i) {
        if (polynomal._terms[i].getCoeff() != 0) {
            q++;
            isNull = false;
        }
        if (q > 1 && polynomal._terms[i].getCoeff() > 0) {
            out << '+';
        }
        out << polynomal._terms[i];
    }
    if (isNull) { out << 0; }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomal &polynomal) {
    size_t count;
    in >> count;
    Term temp;
    for (size_t i = 0; i < count; ++i) {
        in >> temp;
        polynomal += temp;
    }
    return in;
}

Polynomal &Polynomal::operator+=(const Term &term) {
    if (term._power > _maxpower) {
        _maxpower++;
        while (_maxpower != term._power) {
            if (_maxpower >= _terms.Maxsize()) {
                _terms.add_element(Term(0, _maxpower));
            } else {
                _terms[_maxpower] = Term(0, _maxpower);
            }
            _maxpower++;
        }
        _terms[_maxpower] = term;
    } else {
        _terms[term._power] += term;
    }
    return *this;
}

Polynomal &Polynomal::operator+=(const Polynomal &polynomal) {
    Polynomal result(*this);
    bool isNeededToInsert = true;
    for (size_t i = 0; i < polynomal._maxpower + 1; ++i) {
        for (size_t j = 0; j < _maxpower + 1; ++j) {
            if (polynomal._terms[i]._power == _terms[j]._power) {
                result._terms[j] += polynomal._terms[i];
                isNeededToInsert = false;
                break;
            }
        }
        if (isNeededToInsert) {
            result._terms.add_element(polynomal._terms[i]);
        }
        isNeededToInsert = true;
    }

    result._maxpower = result._terms.Size() - 1;
    *this = result;

    return *this;
}

Polynomal &Polynomal::operator*=(const Polynomal &polynomal) {
    MyVector<int> newCoeffs(0, polynomal._maxpower + _maxpower);
    for (size_t i = 0; i < polynomal._maxpower + _maxpower + 1; ++i) {
        newCoeffs[i] = 0;
    }
    for (size_t i = 0; i < _maxpower + 1; ++i) {
        for (size_t j = 0; j < polynomal._maxpower + 1; ++j) {
            newCoeffs[i + j] += polynomal._terms[j].getCoeff() * _terms[i].getCoeff();
        }
    }
    Polynomal result(polynomal._maxpower + _maxpower);
    for (size_t i = 0; i < polynomal._maxpower + _maxpower + 1; ++i) {
        result._terms[i]._coefficient = newCoeffs[i];
    }

    *this = result;
    return *this;

}

Polynomal operator+(Polynomal p1, Polynomal p2) {
    Polynomal result = p1;
    result += p2;
    return result;
}

Polynomal operator*(Polynomal p1, Polynomal p2) {
    Polynomal result = p1;
    result *= p2;
    return result;
}

