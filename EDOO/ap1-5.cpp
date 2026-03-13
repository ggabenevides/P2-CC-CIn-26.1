#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
    std::string message("I have learned something new again!");
    std::cout << message << std::endl;
    int len = message.length();
    std::cout << "Length of the message: " << len << std::endl;
    std::cin.ignore();
    std::getline(std::cin, string1); 
    return 0;
}