#ifndef rational_hpp
#define rational_hpp

#include <iostream>
#include <cassert>

/*
 This is a class for creating instances of rational numbers (also known as fractions).
 A rational number (or fraction) consists of an integer numerator and an integer denominator.
 For this reason, our class has member variables called 'num' and 'den' of type int.

 The default constructor creates 0.
 We can write 0 as 0/1, i.e. with numerator 0 and denominator 1.

 Any integer can be regarded as a fraction with denominator equal to 1.
 There's a constructor based on this idea too.

 Finally, a user can specify a numerator and denominator
 in order to construct a rational of their choice.

 Rationals are always stored in a simplified form:
  - den is strictly positive,
  - num and den have a highest common factor of 1.

 We have implemented all the usual arithmetic operations:
 + (unary and binary), - (unary and binary), *, /,
 +=, -+, *=, /=, ++ (pre and post), -- (pre and post).

 We have implemented the comparison operators:
 ==, !=, <, >, <=, >=.

 We have defined how to static_cast a Rational to a double.

 Finally, we have defined operator<< and operator>>.
*/
class Rational {
public:
    Rational();
    Rational(int _num);
    Rational(int _num, int _den);
    
    //arithmetic update
    Rational& operator+=(const Rational& plus);
    Rational& operator-=(const Rational& minus);
    Rational& operator*=(const Rational& multi);
    Rational& operator/=(const Rational& divi);
    
    //post
    Rational& operator++();
    Rational& operator--();
    //pre
    Rational operator++(int);
    Rational operator--(int);
    //unary
    Rational operator+() const;
    Rational operator-() const;
    
    //binary
    Rational operator+(const Rational& r2) const;
    Rational operator-(const Rational& r2) const;
    Rational operator*(const Rational& r2) const;
    Rational operator/(const Rational& r2) const;
    
    //decimal/doouble
    operator double() const;

private:
    int num;
    int den;

    void make_den_pos(); 
    void simplify();
    
    ///NON-MEMBER FUNCTION ACCESS
    ///
    friend bool operator==(const Rational&, const Rational&);
    friend bool operator< (const Rational&, const Rational&);

    friend std::ostream& operator<<(std::ostream&, const Rational&);
};


std::istream& operator>>(std::istream&, Rational&);

#endif /* rational_hpp */
