#include <iostream>

namespace TOOL1 {
    #include "tool1.h"
}

namespace TOOL2 {
    #include "tool2.h"
}

int main() {
    double val1 = 10.5;
    double val2 = 2.0;

    double sum = TOOL1::calculate(val1, val2);
    
    double product = TOOL2::calculate(val1, val2);

    std::cout << "Testing with values: " << val1 << " and " << val2 << std::endl;
    std::cout << "TOOL1::calculate (Sum):     " << sum << std::endl;
    std::cout << "TOOL2::calculate (Product): " << product << std::endl;

    return 0;
}