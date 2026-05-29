#include "listArray.hpp"

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

void AList::append(int& x)
{
    if (currSize != maxSize)
    {    
        listArray[currSize] = x;
        currSize++;
    }
}

int AList::remove()
{
    int temp = listArray[currPos];
    for (int i = currPos; i < currSize; i++)
    {
        listArray[i] = listArray[i+1];
    }
    currSize--;
    return temp;
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
    if (currPos != 0)
    {
        currPos--;   
    }
   
}

void AList::next()
{
    if (currPos != maxSize - 1)
    {
        currPos++;   
    }
}

void AList::moveToStart()
{
    currPos = 0;
}

void AList::moveToEnd()
{
    currPos = currSize-1;
}

void AList::clear()
{
    delete[] listArray;
    currPos = currSize = 0;
    listArray = new int[maxSize];
}

