#include <iostream>
#include "rational.hpp"

int main() {
    Rational& r();
    Rational& r2();
    Rational& r3();
    Rational& r4();
    Rational& r5();

    std::cout << "Type a rational in the form num/den, and I'll say it back at you: ";
    std::cin  >> r;
    std::cout << "This is your rational: " << &r << std::endl;
    std::cout << "Type a rational in the form num/den, and I'll say it back at you: ";
    std::cin  >> r2;
    std::cout << "This is your rational: " << &r2 << std::endl;
    std::cout << "Type a rational in the form num/den, and I'll say it back at you: ";
    std::cin  >> r3;
    std::cout << "This is your rational: " << &r3 << std::endl;
    std::cout << "Type a rational in the form num/den, and I'll say it back at you: ";
    std::cin  >> r4;
    std::cout << "This is your rational: " << &r4 << std::endl;
    std::cout << "Type a rational in the form num/den, and I'll say it back at you: ";
    std::cin  >> r5;
    std::cout << "This is your rational: " << &r5 << std::endl;
    
    Rational& operator+= (Rational& aduh);
    std::cout <<  operator+=(&aduh) <<  std::endl;
    
//    Rational operator-=(r3);
//    Rational& operator*=(multi);
//    Rational& operator/=(const Rational& divi);
    return 0;
    
}
