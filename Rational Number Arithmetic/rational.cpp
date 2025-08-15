#include "rational.hpp"

// the case for 0
Rational::Rational()                   : num(   0), den(   1) {}//clean constructor
//case for whole number rational
Rational::Rational(int _num)           : num(_num), den(   1) {}//initialized constructor

//actual rational
Rational::Rational(int _num, int _den) : num(_num), den(_den) {
    assert(den != 0);
    make_den_pos();
    simplify();
}

/**
This member function makes sure that
the denominator of a rational number is positive,
a convenient choice.
*/
void Rational::make_den_pos() {
    if (den < 0) {
        num *= -1; // turns numerator negative
        den *= -1; // turns the denominator positive
    }
}

/**
This member function simplifies a rational number.
It does so by computing the highest common factor
of the numerator and denominator and dividing
the numerator and denominator by it.

To compute the highest common factor,
the Euclidean algorithm is used.
Do not worry if you don't know the Euclidean algorithm.
*/
void Rational::simplify() {
    int a = abs(num);       //makes it positive
    int b = abs(den);       //makes it positive

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    num /= a;
    den /= a;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    int num;
    int den;

    char forwardslash;

    in >> num >> forwardslash >> den;

    if (forwardslash != '/') {
        in.setstate(std::ios_base::failbit);
    }
    if (in) {
        r = Rational(num, den);
    }

    return in; // in is the altered rational that they originally put in but alterd -- use and operator most likely "/" that will be the function for removing the rounding decimals 
}
//#1
std::ostream& operator<<(std::ostream& out, const Rational& r){
    int num = r.num;
    int den = r.den;
    char forwardslash = '/';
    
    out << num << forwardslash << den;

    return out;
}


//#2
Rational& Rational::operator+=(const Rational& plus){
    //      a    d             b     c
    num = num * (plus.den) + plus.num * (den);
    den = den* plus.den; // b d
    simplify();

    return *this;
}
//#2
Rational& Rational::operator-=(const Rational& minus){
    
    //      a    d                  c     b
    num = num * (minus.den) - minus.num * den;
    //      b        d
    den = den * (minus.den);

    simplify();
    return *this;

}
//#2
Rational& Rational::operator*=(const Rational& multi){
   //       a        c
    num = num * multi.num;
  //        b       d
    den = den * multi.den;
    simplify();
    
    return *this;
}
//#2
Rational& Rational::operator/=(const Rational& divi){
    //      a        d
    num = num * divi.den;
    //      b        c
    den = den * divi.num;
    
    simplify();
    return *this;
}

//#3 = post
Rational& Rational::operator++() {
    num+=den;
    simplify();
    return *this;
}
//#3 = post
Rational& Rational::operator--() {
    num-=den;
    simplify();
    return *this;
}

//#3
Rational Rational::operator++(int unused) {
    Rational pre_increment(*this); // using implicitly defined copy constructor
    ++(*this);
    simplify();
    return pre_increment;
}
//#3
Rational Rational::operator--(int unused) {
    Rational pre_decrement(*this); // using implicitly defined copy constructor
    --(*this);
    simplify();
    return pre_decrement;
}

//#4
Rational Rational::operator+() const{
    return *this;
 }

//#4

Rational Rational::operator-() const{
    Rational copy(*this);
    copy.num = (copy.num * -1);
    return copy;
    
 }
// Operator+
Rational Rational::operator+(const Rational& r2) const {
    Rational resultPlus;
    resultPlus.num = num * r2.den + r2.num * den;
    resultPlus.den = den * r2.den;
    return resultPlus;
}

// Operator-
Rational Rational::operator-(const Rational& r2) const {
    Rational resultMin;
    resultMin.num = num * r2.den - r2.num * den;
    resultMin.den = den * r2.den;
    return resultMin;
}

// Operator*
Rational Rational::operator*(const Rational& r2) const {
    Rational resultMul;
    resultMul.num = num * r2.num;
    resultMul.den = den * r2.den;
    return resultMul;
}

// Operator/
Rational Rational::operator/(const Rational& r2) const {
    Rational resultDiv;
    resultDiv.num = num * r2.den;
    resultDiv.den = den * r2.num;
    return resultDiv;
}

//#6
bool operator==(const Rational& first, const Rational& second){
    return first.num == second.num && first.den == second.den;
}
//#6
bool operator < (const Rational& first, const Rational& second){
    
    return first.num * second.den < second.num * first.den;
 
}
//#7
bool operator!=(const Rational& firstComp, const Rational& secondComp){
    return !(firstComp == secondComp);
}
//#7

bool operator>(const Rational& firstComp, const Rational& secondComp){
    return !(firstComp < secondComp);
}
//#7

bool operator <=(const Rational& firstComp, const Rational& secondComp){
    return (firstComp < secondComp || firstComp == secondComp);
    
}
//#7

bool operator >= (const Rational& firstComp, const Rational& secondComp) {
   return (firstComp== secondComp || firstComp > secondComp);
}
//#8
Rational::operator double() const{
   
    double one = num/1.0;
    double two = den/1.0;
    
    return one/two;
    
}
