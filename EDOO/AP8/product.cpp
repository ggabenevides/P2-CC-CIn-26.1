#include "product.h"
#include "prepackedFood.h"
#include "freshfood.h"
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

void Product::record()
{
    Product* list[100] = {nullptr};
    int count = 0; 
    long totalPrice = 0;

    for (int i = 0; i < 100; i++)
    {
        char answer;
        std::cout << "Is this Product Fresh or Prepacked? (f/p, any other key to stop): ";
        std::cin >> answer;

        if (answer != 'f' && answer != 'p')
        {
            break;
        }

        if (answer == 'p')
        {
            std::string name;
            long price, barcode;
            std::cout << "Insert Product name: "; std::cin >> name;
            std::cout << "Insert Product price: "; std::cin >> price;
            std::cout << "Insert Product barcode: "; std::cin >> barcode;
            
            totalPrice += price;
            list[count] = new PrepackedFood(price, barcode, name);
            count++;
        }
        else if (answer == 'f')
        {
            std::string name;
            long price, barcode, weight;
            std::cout << "Insert Product name: "; std::cin >> name;
            std::cout << "Insert Product price per kilo: "; std::cin >> price;
            std::cout << "Insert Product barcode: "; std::cin >> barcode;
            std::cout << "Insert Product weight: "; std::cin >> weight;
            
            totalPrice += price;
            list[count] = new FreshFood(price, name, barcode, weight);
            count++;
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (list[i] != nullptr)
        {
            list[i]->printer();
        }
    }
    std::cout << "Total price: " << totalPrice << std::endl;

    for (int i = 0; i < count; i++)
    {
        delete list[i];
    }
    delete[] list;
}