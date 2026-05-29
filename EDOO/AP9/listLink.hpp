#ifndef LIST_LINK_HPP
#define LIST_LINK_HPP

class Link
{
    public:
        int element;
        Link* next; 
        Link(const int& elemval, Link* nextval = nullptr);
        Link(Link* nextval = nullptr);
};

class LList
{
    private:
        Link *head, *tail, *curr;
        int currSize;
        
    public:
        LList();
        ~LList();
        void insert(int& x);
        void append(int& x);
        int remove();
        int count(int& x);
        void prev();
        void next();
        void moveToStart();
        void moveToEnd();
        void clear();
};

#endif