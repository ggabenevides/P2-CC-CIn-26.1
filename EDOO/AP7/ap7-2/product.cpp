#include "product.h"
#include <iostream>
#include <string>

Product::Product(long b, std::string n)
{
    barcode = b;
    productName = n;
}

void Product::scanner(long b)
{
    if (b == barcode){
        std::cout << "Product name: " << productName << std::endl;
    }
}

void Product::printer()
{
    std::cout << "Product barcode: " << barcode << std::endl;
    std::cout << "Product name: " << productName << std::endl;
}