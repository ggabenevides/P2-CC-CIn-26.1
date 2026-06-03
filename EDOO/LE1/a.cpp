#include "carQueue.hpp"
#include <iostream>
#include <string>

int main()
{
    int caseCount;
    std::cin >> caseCount;
    for (int i=1; i<=caseCount; i++)
    {
        std::string caseDescription;
        getline(std::cin, caseDescription);
        int ferryLen = std::stoi(caseDescription.substr(0, 2));
        int caseSize = std::stoi(caseDescription.substr(3));
        for (int j = 1; j <= caseSize; j++)
        {
            
        }
    }
}