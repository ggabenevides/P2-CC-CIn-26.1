#include "stack.hpp"
#include <stdexcept>

LStack::LStack()
{
    top = new Link();
    size = 0;
}

LStack::~LStack()
{
    clear();
    delete top;

}

void LStack::clear()
{
    while(size !=0)
    {
       pop();
    }
}

int LStack::pop()
{
    Link* temp = top->next; //variavel temporaria p evitar memory leak
    top->next = top->next->next; //desconectar link da stack
    size--; //ajustar tamanho
    int value = temp->element;
    delete temp;
    return value;
}

void LStack::push(int& e)
{
    top->next = new Link(e, top->next);
    size++;
}