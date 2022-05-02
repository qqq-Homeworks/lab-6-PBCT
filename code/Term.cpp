// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>


#include "Term.hpp"
#include "Polynomal.hpp"


std::ostream &operator<<(std::ostream &out, const Term &term) {
    if (term._coefficient == 0) {
        out << '0';
    } else {
        if (term._power == 0) {
            out << term._coefficient;
        } else if (term._power == 1) {
            out << term._coefficient << 'x';
        } else {
            out << term._coefficient << 'x' << '^' << term._power;
        }
    }
    return out;
}


std::istream &operator>>(std::istream &in, Term &term) {
    in >> term._coefficient;
    if(in.fail()) {
        in.clear();
        in.ignore();
        term._coefficient = 1;
        if (in.peek()=='x'){
            in.get();
            if (in.peek()=='^'){
                in.get();
                in >> term._power;
                return in;
            }
            else{
                term._power = 1;
                return in;
            }
        } else{
            term._power = 0;
            return in;
        }
    } else
    {
        if (in.peek()=='x'){
            in.get();
            if (in.peek()=='^'){
                in.get();
                in >> term._power;
                return in;
            }
        } else{
            term._power = 0;
            return in;
        }
    }
    return in;
}

Term &Term::operator+=(Term &term) {
    _coefficient += term._coefficient;
    return *this;
}

Term operator+(Term &s1, Term &s2) {
    return s1 += s2;
}