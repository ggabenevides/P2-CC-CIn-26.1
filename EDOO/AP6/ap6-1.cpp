#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int* splice(int array1[], int array2[], int len1, int len2, int position);

int main(){
    cout << "Testing splice(): \n";

    // creating variables
    int i, len1 = 10, len2 = 5;
    int *a1 = new int[len1], *a2 = new int[len2];

    // initializing arrays
    srand( (unsigned)time(NULL));
    for( i=0; i < len1; ++i) 
    {   
        a1[i] = rand();
    }
    for( i=0; i < len2; ++i)
    {
        a2[i] = -rand();
    }

    // display arrays
    cout << "1. array: " << endl;
    for( i = 0; i < len1; ++i)
    {
        cout << setw(12) << a1[i];
    }
    cout << endl;
    cout << "2. array: " << endl;
    for( i = 0; i < len2; ++i)
    {
        cout << setw(12) << a2[i];
    }
    cout << endl;

    // input to call splice
    cout << "\n At what position do you want to insert "
    "\n the 2nd array into 1st array?"
    "\n Possible positions: 0, 1, ..., " << len1 << " : ";
    int pos; 
    cin >> pos;

    //call to splice
    int* new_array = splice(a1, a2, len1, len2, pos);

    // display new array
    cout << "3. array: " << endl;
    for( i = 0; i < len2+len1; ++i)
    {
        cout << setw(12) << new_array[i];
    }
    cout << endl;
    
    delete[] new_array; 

}

int* splice(int array1[], int array2[], int len1, int len2, int position)
{
    if( position < 0 || position > len1)
        {return NULL;}
    int* array = new int[len1+len2];
    int i, i1, i2;
    for (i = 0, i1=0; i1 < position; i++, i1++)
    {
        array[i] = array1[i1];
    }
    for (i2=0; i2<len2; i++, i2++)
    {
        array[i] = array2[i2];
    }
    for ( ; i1<len1; i++, i1++)
    {
        array[i]=array1[i1];
    }
    
    delete[] array1;
    delete[] array2;
    return array;
}