#include "article.h"
#include <iostream>
using namespace std;

int count = 0;

void Article::print()
{
    cout << "Article name: " << name << endl;
    cout << "Article number: " << number << endl;
    cout << "Article price: $" << price << endl;
}

Article::Article(long n = 0, const string& s = "Not provided", double p = 0.0)
{
    number = n;
    name = s;
    (p >= 0) ? price = p : price = 0.0;

    cout << "An object of type Article " << name << " is created." << endl;
    cout << "This is the" << count << "Article." << endl;

    ++count;
}

Article::~Article()
{
    --count;
    cout << "The object of type Article" << name << "is destroyed." << endl;
    cout << "There are still" << count << "articles." << endl;
}