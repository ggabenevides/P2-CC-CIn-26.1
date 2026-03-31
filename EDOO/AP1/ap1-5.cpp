#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
    std::string message("I have learned something new again!");
    std::cout << message << std::endl;
    int len = message.length();
    std::cout << "Length of the message: " << len << std::endl;

    std::string string1, string2;
    std::getline(std::cin, string1); 
    std::getline(std::cin, string2);
    std::cout << string1 << " * " << string2 << std::endl;
    return 0;
}