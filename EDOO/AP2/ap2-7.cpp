#include <iostream>
#include "macros.h"

int main(){
    signed int negNumber(-5);
    int x(3), y(4);

    int absolute = ABS(negNumber);
    int compare = MAX(x,y);
    std::cout << "absolute value of -5: " << absolute << std::endl;
    std::cout << "bigger number between 3 and 4: " <<compare << std::endl;
    return 0;
}