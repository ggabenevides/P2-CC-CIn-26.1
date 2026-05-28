#include "list.hpp"

AList::AList(int max)
{
    maxSize = max;
    currPos = currSize = 0;
    listArray = new int[max];
}

AList::~AList()
{
    delete[] listArray;    
}

void AList::insert(int& x)
{
    for (int i = maxSize; i > currPos; i--)
    {
        listArray[i] = listArray[i-1];
    }
    listArray[currPos] = x;
    currSize++;
}

void AList::remove()
{
    for (int i = currPos; i < currSize; i++)
    {
        listArray[i] = listArray[i+1];
    }
    currSize--;
}

int AList::count(int& x)
{
    int count(0);
    for (int i = 0; i < currSize; i++)
    {
        if (listArray[i] == x)
        {
            count++;
        }
    }
    return count;
}

void AList::prev()
{
   currPos--; 
}

void AList::next()
{
   currPos++; 
}

void AList::clear()
{
    delete[] listArray;
    currPos = currSize = 0;
    listArray = new int[maxSize];
}