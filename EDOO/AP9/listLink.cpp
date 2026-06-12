#include "listLink.hpp"
#include <iostream>

Link::Link(const int& elemval, Link* nextval)
{
    element = elemval;
    next = nextval;
}

Link::Link(Link* nextval)
{
    next = nextval;
}

LList::LList()
{
    currSize = 0;
    curr = tail = head = new Link();
}

LList::~LList()
{
    clear();
    delete head;
}

void LList::clear()
{
    while (head != nullptr)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

void LList::insert(int& x)
{
    curr->next = new Link(x, curr->next);
    if (tail==curr) tail = curr->next;
    currSize++;
}

void LList::append(int& x)
{
    tail = tail->next = new Link(x);
    currSize++;
}

int LList::remove()
{
    if (curr->next == nullptr) return -1; // refine error handling in the future maybe?
    Link* temp = curr->next; // storing current node so we can free the space
    int it = curr->next->element; // storing current node value so we can return it
    curr->next = curr->next->next; // reassign next pointer
    if (tail == temp) tail = curr; // reassign tail if removed element is also tail
    currSize--;
    delete temp;
    return it;
}

//returns the amount of times the value x is stored in the list
int LList::count(int& x)
{
    Link* tempPtr = head->next; //access first value on the list
    int amount(0);
    while (tempPtr != nullptr) //while end of list is not reached
    {
        if (tempPtr->element == x) amount++; // analyzing whether current value being assessed is the value we're looking for
        tempPtr = tempPtr->next; //move pointer to next element
    }
    return amount; 
}

void LList::prev()
{
    if (curr == head) return; // can't move to previous posistion because it doesnt exist
    Link* tempPtr = head;
    while (tempPtr != nullptr) //while end of list is not reached
    {
        if (tempPtr->next == curr) 
        {
            curr = tempPtr;
            break;
        }
        tempPtr = tempPtr->next; 
    }
}

void LList::next()
{
    if (curr == tail) return; // can't move to next posistion because it doesnt exist
    curr = curr->next; 
}

void LList::moveToStart()
{
    curr = head;
}

void LList::moveToEnd()
{
    curr = tail;
}

int LList::peekCurrElement () {return curr->element;}

Link* LList::peekCurrPtr() {return curr->next;}

void LList::display()
{
    Link* tempPtr = head->next;
    while (tempPtr != nullptr)
    {
        std::cout << tempPtr->element << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}