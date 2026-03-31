#include <iostream>
#include <iomanip>

int main()
{
    float n(0.123456);
    float n2(23.987);
    float n3(-123.456);
    std::cout << std::setw(15) << std::left << n << std::endl;
    std::cout << std::setw(12) << std::right << std::fixed << std::setprecision(2) << n2 << std::endl;
    std::cout <<std::setw(10) << std::setprecision(4) << std::scientific <<n3 << std::endl; // field of 10 is not very useful here
}