#include "fraction.h"

Fraction::Fraction(long num, long denom)
{
    if (denom == 0){
        throw DivisionByZero();
    }
    if (denom < 0) { 
        num = -num, denom = -denom; 
    }

    numerator = num, denominator = denom;
}

Fraction::Fraction(int num): numerator(num), denominator(1){} //conversion constructor

Fraction Fraction::operator-() const
{
    return Fraction(-numerator, denominator);
}

Fraction& Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& obj) 
{
    numerator = numerator*obj.denominator + obj.numerator*denominator;
    denominator = obj.denominator*denominator;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& obj) 
{
    *this += -obj;
    return *this;
} 

Fraction& Fraction::operator/=(const Fraction& obj) 
{
    numerator *= obj.denominator;
    denominator *= obj.numerator;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& obj) 
{    
    numerator *= obj.numerator;
    denominator *= obj.denominator;
    return *this;
}

// friend functions for + - * / << >>
Fraction operator+(const Fraction& lhs, const Fraction& rhs)
{
    Fraction temp = lhs; 
    temp += rhs;       
    return temp;
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs)
{
    Fraction temp = lhs;
    temp -= rhs;        
    return temp;
}
Fraction operator*(const Fraction& lhs, const Fraction& rhs)
{
    Fraction temp;
    temp.numerator = lhs.numerator*rhs.numerator;
    temp.denominator = lhs.denominator*rhs.denominator;
    return temp;  
}
Fraction operator/(const Fraction& lhs, const Fraction& rhs)
{
    Fraction temp;
    if (rhs.denominator == 0)
    {
        throw Fraction::DivisionByZero();
    }
    temp.numerator = lhs.numerator*rhs.denominator;
    temp.denominator = rhs.numerator*lhs.denominator;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    os << obj.numerator << "/" << obj.denominator << endl;
    return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
    cout << "Enter a fraction: \n";
    cout << "Numerator: ";
    is >> obj.numerator;
    cout << "Denominator: ";
    is >> obj.denominator;

    if (!is) return is;

    if (obj.denominator == 0)
    {
        throw Fraction::DivisionByZero();
    }

    if (obj.denominator < 0) { 
        obj.numerator = -obj.numerator, obj.denominator = -obj.denominator; 
    }
    return is;
}