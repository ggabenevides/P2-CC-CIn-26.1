#include "product.h"
#include "freshfood.h"
#include <iostream>

FreshFood::FreshFood(long p, long n, long b, long w) : Product(b, n)
{
    weight = w;
    priceKilo = p;
}

void FreshFood::scanner(long b)
{
    if (b == this->getCode()){
        std::cout << "Product name: " << this->getName() << std::endl;
        std::cout << "Price per kilogram: " << priceKilo << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }
}

void FreshFood::printer()
{
    std::cout << "Product barcode: " << this->getCode() << std::endl;
    std::cout << "Product name: " << this->getName() << std::endl;
    std::cout << "Price per unit: " << priceKilo << std::endl;
    std::cout << "Weight: " << weight << std::endl;
}