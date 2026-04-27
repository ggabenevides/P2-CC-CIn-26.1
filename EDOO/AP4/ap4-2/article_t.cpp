#include "article.h"
#include <iostream>
using namespace std;

Article globalObj(123, "Book", 49.99);

void test(){
    Article localObj2(7, "Water Bottle", 1.99);
    Article localObj3(6, "Protein Bar", 8.99);
    // one of the objects has to have static definitions
    localObj2.print();
    localObj3.print();
    cout << "Function 'test' terminated.";

}

int main(){
    Article localObj(23, "Pencil", 3.00);
    test();
    //test need to be called twice
    //call the access methods to modify individual data members and display the objects on screen
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