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
        static int count;
        static int getCount(){return count;}
    
    public:
        Article(long n = 0, const string& s = "Not provided", double p = 0.0); //constructor with default values
        Article(const Article&); // copy constructor
        ~Article(); //destructor
        void print(); //display method

        // access methods: must be inline
        //get methods for each data member:
        long getNumber() {return number;}
        string getName() {return name;}
        double getPrice() {return price;}

        //set methods for each data member:
        void setNumber(long n) {number = n;}
        void setName(string s) {name = s;}
        void setPrice(double p) {(p >= 0) ? price = p : price = 0.0;}        

};

#endif