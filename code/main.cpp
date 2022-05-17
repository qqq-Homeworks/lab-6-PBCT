#include <iostream>
#include "Polynomal.hpp"

int main() {

    Term a, b;
    Polynomal ap, bp, ed(Term(-1, 0));

    std::cin >> ap;
    std::cout << ap << '\n';
    std::cin >> bp;
    std::cout << bp << '\n';
    ed *= bp;
    std::cout << ed << '\n';
//    ap += bp;
//    std::cout << ap << '\n';
//    ap *= bp;
//    std::cout << ap << '\n';
    return 0;
}
