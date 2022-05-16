#include <iostream>
#include "Polynomal.hpp"

int main() {

    Term a, b;
    std::cin >> a;
    std::cin >> b;
    Polynomal ap(a), bp(b), cp;
    std::cin >> cp;
//    cp+=a;
//    cp+=b;
//    cp*=ap;
//    cp*=cp;
    //std::cout << ap << '\n';
    //cp *= ap;
    std::cout << cp;

    return 0;
}
