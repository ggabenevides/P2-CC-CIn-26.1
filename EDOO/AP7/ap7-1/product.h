#ifndef _PRODUCT_
#define _PRODUCT_
#include <string>

class Product
{
    private:
        long barcode;
        std::string productName;

    public:
        Product(long b = 0, std::string n = "noInfo");
        void setCode (long b) {barcode = b;}
        long getCode(){return barcode;}
        void setName (std::string n) {productName = n;}
        std::string getName(){return productName;}
        void scanner(long b);
        void printer();

};

#endif