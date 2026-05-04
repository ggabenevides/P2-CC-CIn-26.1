#include "fraction.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
        Fraction obj(3,0);
        Fraction objOk(0, 3);
    }
    catch(const Fraction::DivisionByZero&)
    {
        cout << "Error on initializing: the denominator is 0.\n";
    }

    Fraction a(4, 3);
    Fraction b(0);
    try
    {
        a/b;
    }
    catch(const Fraction::DivisionByZero&)
    {
        cout << "Error on division: can't divide by 0.\n";
    }

    Fraction c(3,0);
    try
    {
        cin >> c;
    }
    catch(const Fraction::DivisionByZero&)
    {
        cout << "Error on input: denominator is 0. \nEnter a new denominator !=0: ";
        long newDenom;
        std::cin >> newDenom;
        if (newDenom == 0) {
            std::cerr << "New denominator != 0: " << newDenom << std::endl;
            exit(1);
        }
        std::cout << "Corrected denominator to " << newDenom << "." << std::endl;
    }
    
    
}