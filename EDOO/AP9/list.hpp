#ifndef LIST_HPP
#define LIST_HPP

class AList
{
    private:
        int maxSize, currSize, currPos;
        int* listArray;
    public:
        AList(int max);
        ~AList();
        void insert(int& x);
        void remove();
        int count(int& x);
        void prev();
        void next();
        void clear();
};

#endif