#include "prepackedFood.h"
#include "product.h"
#include "freshfood.h"
#include <iostream>

int main()
{
    Product init(67, "SixSeven");
    Product nonInit;
    nonInit.setCode(23);
    nonInit.setName("Boy");
    init.printer();
    nonInit.printer();

    FreshFood init2(67, "Gabi", 789, 99.3);
    FreshFood nonInit2;
    nonInit2.setCode(23);
    nonInit2.setName("Ball");
    nonInit2.setPrice(333);
    nonInit2.setWeight(22.3);
    init2.printer();
    nonInit2.printer();

    PrepackedFood init3(67, 789, "Salt");
    PrepackedFood nonInit3;
    nonInit2.setCode(23);
    nonInit2.setName("JESUS");
    nonInit2.setPrice(333);
    init3.printer();
    nonInit3.printer();
}
