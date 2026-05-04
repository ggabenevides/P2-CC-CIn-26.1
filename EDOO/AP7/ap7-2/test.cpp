#include "prepackedFood.h"
#include "product.h"
#include "freshfood.h"
#include <iostream>

Product& isLowerCode(Product &obj1, Product &obj2);

int main()
{
    Product** a1 = new Product*[3];
    a1[0] = new Product(1, "Beans");
    a1[1] = new FreshFood(78, "Rice", 2, 1.0);
    a1[2] = new PrepackedFood(19, 3, "Beans");

    FreshFood* obj = new FreshFood(23, "gabi", 4, 73.5);

    a1[0]->printer();
    //downcast
    static_cast<FreshFood*>(a1[1])->printer();
    static_cast<PrepackedFood*>(a1[2])->printer();
    //upcast
    static_cast<Product*>(obj)->printer();

    isLowerCode(*a1[0], *a1[1]).printer();
    isLowerCode(*a1[1], *a1[2]).printer();
    
    delete a1[0]; delete a1[1]; delete a1[2]; delete[] a1;
    delete obj;

}

Product& isLowerCode(Product &obj1, Product &obj2)
{
    if (obj1.getCode() < obj2.getCode())
    {
        return obj1;
    }
    else if (obj2.getCode() < obj1.getCode())
    {
        return obj2;
    }
}
