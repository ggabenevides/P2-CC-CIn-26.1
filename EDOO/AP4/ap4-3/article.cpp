#include "article.h"
#include <iostream>
using namespace std;

int Article::count = 0;

void Article::print()
{
    cout << endl;
    cout << "Article name: " << name << endl;
    cout << "Article number: " << number << endl;
    cout << "Article price: $" << price << endl;
    cout << endl;
}

Article::Article(long n, const string& s, double p)
{
    number = n;
    name = s;
    (p >= 0) ? price = p : price = 0.0;
    ++count;

    cout << endl;
    cout << "An object of type Article " << name << " is created." << endl;
    cout << "This is the " << count << "º Article." << endl;
    cout << endl;

    
}

Article::Article(const Article& obj): Article(obj.number, obj.name, obj.price)
{

    cout << endl;
    cout << "Object of type Article created by copying " << name << "." << endl;
    cout << "This is the " << count << "º Article." << endl;
    cout << endl;

}

Article::~Article()
{
    --count;
    cout << endl;
    cout << "The object of type Article " << name << " is destroyed." << endl;
    cout << "There are still " << count << " articles." << endl;
    cout << endl;
}