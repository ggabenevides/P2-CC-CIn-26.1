#include <iostream>

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
        void append(int& x);
        int remove();
        int count(int& x);
        int peekCurrElement();
        Link* peekCurrPtr();
        void next();
        void moveToStart();
        void clear();
        void display();
};

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

void LList::next()
{
    if (curr == tail) return; // can't move to next posistion because it doesnt exist
    curr = curr->next; 
}

void LList::moveToStart()
{
    curr = head;
}

int LList::peekCurrElement () {return curr->next->element;}
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


class Dictionary
{
    private:
        int m; //hash table size
        int cnt; //amount of elements 
        LList** H; //array of pointer to lists (each position is a key, each key has a list with all of the number attributed to it)
        int hash(int x){return x%10;} //hash function

    public:
        Dictionary(int size)
        {
            m = size;
            cnt = 0;
            H = new LList*[m];
            for (int i = 0; i < m; i++)
            {
                H[i] = new LList;
            }
        }
        LList* search(int k)
        {
            int h = hash(k);
            LList* keyList = H[h];
            if (keyList -> count(k) != 0) return keyList;
            else return nullptr;

        }
        void insert(int k)
        {
            int h = hash(k);
            if (search(k) != nullptr) return;
            H[h] -> append(k);
            cnt++;
        }
        void remove(int k)
        {
            int h = hash(k);
            if (search(k) == nullptr) return;
            H[h] -> moveToStart(); //make sure to start iteratig over list from the beginning
            while (H[h] -> peekCurrPtr() != nullptr)
            {
                int curr = H[h] -> peekCurrElement();
                if (curr == k)
                {
                    H[h] -> remove();
                    cnt--;
                    return;
                }
                else
                {
                    H[h] -> next();
                }
            }
        }
        void display()
        {
            for (int i = 0; i < m; i++)
            {
                std::cout << i << " ";
                H[i] -> display();
            }
        }
};

int main()
{
    Dictionary dict(10);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element; 
        std::cin >> element;
        dict.insert(element);
    }
    dict.display();
}