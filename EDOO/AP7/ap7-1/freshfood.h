#ifndef _FRESHFOOD_
#define _FRESHFOOD_
#include "product.h"

class FreshFood:public Product
{
    private:
        long priceKilo, weight;
    public:
        FreshFood(long p=0, std::string n= "noInfo", long b=0, long w=0);
        void setPrice(long p){priceKilo = p;}
        long getprice(){return priceKilo;}
        void setWeight(long w){weight = w;}
        long getWeight(){return weight;}
        void scanner(long b);
        void printer();
};

#endif