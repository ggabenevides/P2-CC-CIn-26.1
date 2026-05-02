#include "fraction.h"
#include <iostream>
using namespace std;

int main()
{
    Fraction op1(1,2);
    Fraction op2(1,2);
    Fraction temp = op1;

    cout << "Inversed " << op1 << ": " << -op1 << endl;
    
    temp += op2;
    cout << "Sum with unary operator: " << op1 << " + " << op2 << " = " << temp << endl;

    temp = op1; // resetting test
    temp = op1+op2;
    cout << "Sum with dual operator: " << op1 << " + " << op2 << " = " << temp << endl;

    temp = op1;
    temp -= op2;
    cout << "Subtraction with unary operator: " << op1 << " - " << op2 << " = " << temp << endl;
    
    temp = op1; // resetting test
    temp = op1-op2;
    cout << "Subtraction with dual operator: " << op1 << " - " << op2 << " = " << temp << endl;

    temp = op1;
    temp *= op2;
    cout << "Multiplication with unary operator: " << op1 << " * " << op2 << " = " << temp << endl;
    
    temp = op1; // resetting test
    temp = op1*op2;
    cout << "Multiplication with dual operator: " << op1 << " * " << op2 << " = " << temp << endl;

    temp = op1;
    temp /= op2;
    cout << "Division with unary operator: " << op1 << " / " << op2 << " = " << temp << endl;
    
    temp = op1; // resetting test
    temp = op1/op2;
    cout << "Division with dual operator: " << op1 << " / " << op2 << " = " << temp <<endl;

    temp = op1; // resetting test
    ++temp;
    cout << "Incremeting " << op1 << ": " << temp <<endl;

    temp = op1; // resetting test
    --temp;
    cout << "Decrementing " << op1 << ": " << temp <<endl;

    Fraction test1 = 5;
    Fraction test2(3,4);
    cout << "Object init from integer 5: " << test1 << endl;

    Fraction f3 = test1 + Fraction(2); // f1 (5/1) + 2/1 = 7/1
    cout << test1 << " + 2 = " << f3 << endl;

    // Fraction -> double conversion
    double result = test2;   
    cout << "Convert to double: " << result << endl;

    // mixing types in arithmetic
    double mixed = double(test2) + 0.5; // f2 (0.75) + 0.5 = 1.25
    cout << test2 << " + 0.5 = " << mixed << endl;

    cout << "And finally your input: \n";
    cin >> temp;
    cout << temp;
    
    return 0;

}