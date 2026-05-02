#ifndef _FRACTION_
#define _FRACTION_

#include <iostream>
# include <cstdlib>
using namespace std;

class Fraction 
{

    private:

        long numerator;
        long denominator;

    public:

        Fraction(long num=0, long denom=1);
        Fraction(int num);
        
        Fraction operator-();
        Fraction& operator++();
        Fraction& operator--(); 
        Fraction& operator-=(Fraction& obj);
        Fraction& operator+=(const Fraction& obj); 
        Fraction& operator/=(const Fraction& obj); 
        Fraction& operator*=(const Fraction& obj); 
        operator double() {return static_cast<double>(numerator) / denominator;}

        friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
        friend Fraction operator-(const Fraction& lhs, Fraction& rhs);
        friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
        friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

        friend ostream& operator<<(ostream& os, const Fraction& obj);
        friend istream& operator>>(istream& is, Fraction& obj);

};

#endif