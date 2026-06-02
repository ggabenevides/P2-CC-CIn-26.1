#ifndef STACK_HPP
#define STACK_HPP

class Link 
{
    public:
        int element;
        Link* next;
        Link(const int& e=0, Link* n= nullptr)
        {
            element = e;
            next = n;
        }
        ~Link(){}
};

class LStack
{
    private: 
        Link* top;
        int size;
    public:
        LStack();
        ~LStack();
        void clear();
        void push(int& e);
        int pop();
};

#endif
