#include "article.h"
#include <iostream>
using namespace std;

Article globalObj(123, "Book", 49.99);

void test(int n, const string& s, double d){
    Article funcObj(n, s, d);
    static Article staticObj (23, "Gabi", 10000.00);
    funcObj.print();
    staticObj.print();
    cout << "Function 'test' terminated." << endl;
}

int main(){    
    cout << "First statement within main." << endl;
    cout << "Calling global object:" << endl;
    globalObj.print();

    Article localObj(23, "Pencil", 3.00);

    cout << "First call to function 'test" << endl;
    test(7, "Rice", 10.99);
    cout << "Second call to function 'test" << endl;
    test(9, "Beans", 99.10);


    cout << "Test 1: Display Method" << endl;
    localObj.print();   


    cout << "Test 2: Access functions - GET" << endl;
    cout << "Object Name: " << localObj.getName() << endl;
    cout << "Object Number: " << localObj.getNumber() << endl;
    cout << "Object Price: " << localObj.getPrice() << endl;

    localObj.setName("Beans");
    localObj.setPrice(5.50);
    localObj.setNumber(1);

    cout << endl;
    cout << "Test 3: Access functions - SET" << endl;
    localObj.getName();
    localObj.getNumber();
    localObj.getPrice();
    localObj.print();
}

/*
Supplementary question: Suppose you modify the program by declaring a function called test() 
with a parameter of type Article and calling the function with an article type object. The 
counter for the number of objects is negative after running the program. Why?

Answer: because passing an object as a value means that the copy constructor will make another 
object that is a copy of the object passed to serve as parameter to the function, but since the 
copy constructor is different from the default constructor that was defined in article.cpp, it 
won't have the functionality of incremeting the object count, while the destructor used will be 
the one defined in article.cpp and will decrement the obejct count; therefore, the object count 
will not be incremented, but will be decremented.
*/