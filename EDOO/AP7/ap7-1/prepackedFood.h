#ifndef _PREPACKEDFOOD_
#define _PREPACKEDFOOD_
#include "product.h"

class PrepackedFood:public Product
{
    private:
        long unitPrice;
    public:
        PrepackedFood(long p = 0, long n = 0, long b = 0);
        void setPrice(long p){unitPrice = p;}
        long getprice(){return unitPrice;}
        void scanner(long b);
        void printer();
};

#endif