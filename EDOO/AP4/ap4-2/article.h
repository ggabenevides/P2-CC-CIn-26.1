#ifndef _ARTICLE_
#define _ARTICLE_

#include <string>
using namespace std;

class Article 
{
    private:
        long number;
        string name;
        double price;
    
    public:
        Article(long n = 0, const string& = "Not provided", double p = 0.0); //constructor with default values
        ~Article(); //destructor
        void print(); //display method

        // access methods: must be inline
        //get methods for each data member:
        long getNumber() {return number;}
        string getName() {return name;}
        double getPrice() {return price;}

        //set methods for each data member:
        long setNumber(long n) {number = n;}
        string setName(string s) {name = s;}
        double setPrice(double p) {(p >= 0) ? price = p : price = 0.0;}        

};

#endif