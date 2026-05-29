#ifndef LIST_ARRAY_HPP
#define LIST_ARRAY_HPP

class AList
{
    private:
        int maxSize, currSize, currPos;
        int* listArray;
    public:
        AList(int max);
        ~AList();
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