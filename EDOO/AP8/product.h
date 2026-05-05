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
        virtual ~Product(){};
        void setCode (long b) {barcode = b;}
        long getCode(){return barcode;}
        void setName (std::string n) {productName = n;}
        std::string getName(){return productName;}
        virtual void scanner(long b);
        virtual void printer();
        virtual void record();

};

#endif