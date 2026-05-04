#ifndef _PRODUCT_
#define _PRODUCT_

class Product
{
    private:
        long barcode, productName;

    public:
        Product(long b = 0, long n = 0);
        void setCode (long b) {barcode = b;}
        long getCode(){return barcode;}
        void setName (long n) {productName = n;}
        long getName(){return productName;}
        void scanner(long b);
        void printer();

};

#endif