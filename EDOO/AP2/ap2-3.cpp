#include <iostream>

int main ()
{
   int i = -2;
   int x;
   x = -4 * i++ -6 % 4;
   std::cout << x << std::endl;
}