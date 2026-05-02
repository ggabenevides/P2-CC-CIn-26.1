#include "fraction.h"

Fraction::Fraction(long num, long denom)
{
    if (denom == 0){
        cerr << "Error: division by 0.\n";
        exit(1);
    }
    if (denom < 0) { 
        num = -num, denom = -denom; 
    }

    numerator = num, denominator = denom;
}

Fraction::Fraction(int num): numerator(num), denominator(1){} //conversion constructor

Fraction Fraction::operator-()
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

Fraction& Fraction::operator-=(Fraction& obj) 
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
    Fraction temp;
    temp.numerator = lhs.numerator*rhs.denominator + rhs.numerator*lhs.denominator;
    temp.denominator = lhs.denominator*rhs.denominator;
    return temp;
}
Fraction operator-(const Fraction& lhs, Fraction& rhs)
{
    Fraction temp = lhs;
    temp += (-rhs);
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

    if (obj.denominator == 0){
        cerr << "Error: the denominator is 0.\n";
        cout << "Enter a denominator != 0: ";
        is >> obj.denominator;
        if (obj.denominator == 0)
        {
            cerr << "Error: division by 0.\n";
            exit(1);
        }
    }

    if (obj.denominator < 0) { 
        obj.numerator = -obj.numerator, obj.denominator = -obj.denominator; 
    }
    return is;
}