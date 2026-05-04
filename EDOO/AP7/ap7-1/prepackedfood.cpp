#include "product.h"
#include "prepackedFood.h"
#include <iostream>

PrepackedFood::PrepackedFood(long p, long b, long n) : Product(b, n)
{
    unitPrice = p;
}

void PrepackedFood::scanner(long b)
{
    if (b == this->getCode()){
        std::cout << "Product name: " << this->getName() << std::endl;
        std::cout << "Price per unit: " << unitPrice << std::endl;
    }
}

void PrepackedFood::printer()
{
    std::cout << "Product barcode: " << this->getCode() << std::endl;
     std::cout << "Product name: " << this->getName() << std::endl;
     std::cout << "Price per unit: " << unitPrice << std::endl;
}