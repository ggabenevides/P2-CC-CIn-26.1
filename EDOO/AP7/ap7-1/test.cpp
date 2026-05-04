#include "prepackedFood.h"
#include "product.h"
#include "freshfood.h"
#include <iostream>

int main()
{
    Product init(12345, 67);
    Product nonInit;
    nonInit.setCode(23);
    nonInit.setName(0.9);
    init.printer();
    nonInit.printer();

    FreshFood init2(12345, 67, 789, 99.3);
    FreshFood nonInit2;
    nonInit2.setCode(23);
    nonInit2.setName(0.9);
    nonInit2.setPrice(333);
    nonInit2.setWeight(22.3);
    init2.printer();
    nonInit2.printer();

    PrepackedFood init3(12345, 67, 789);
    FreshFood nonInit3;
    nonInit2.setCode(23);
    nonInit2.setName(0.9);
    nonInit2.setPrice(333);
    init3.printer();
    nonInit3.printer();
}
