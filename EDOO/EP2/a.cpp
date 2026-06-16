#include <string>
#include <iostream>
using namespace std;

struct Entry
{
    string name;
    int key;
};

class Link
{
    public:
        Entry element;
        Link* next; 
        Link(const int& key, const string& name, Link* nextval = nullptr);
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
        void append(int& key, string& name);
        string remove();
        int count(int& key);
        int peekCurrElement();
        Link* peekCurrPtr();
        void prev();
        void next();
        void moveToStart();
        void moveToEnd();
        void clear();
        void display();
        int getSize() {return currSize;}
};

Link::Link(const int& key, const string& name, Link* nextval)
{
    element.key = key;
    element.name = name;
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

void LList::append(int& key, string& name)
{
    tail = tail->next = new Link(key, name);
    currSize++;
}

string LList::remove()
{
    if (curr->next == nullptr) return ""; // refine error handling in the future maybe?
    Link* temp = curr->next; // storing current node so we can free the space
    Entry it = curr->next->element; // storing current node value so we can return it
    curr->next = curr->next->next; // reassign next pointer
    if (tail == temp) tail = curr; // reassign tail if removed element is also tail
    currSize--;
    delete temp;
    return it.name;
}

//returns the amount of times the value x is stored in the list
int LList::count(int& key)
{
    Link* tempPtr = head->next; //access first value on the list
    int amount(0);
    while (tempPtr != nullptr) //while end of list is not reached
    {
        if (tempPtr->element.key == key) amount++; // analyzing whether current value being assessed is the value we're looking for
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

int LList::peekCurrElement () {return curr->element.key;}

Link* LList::peekCurrPtr() {return curr->next;}

void LList::display()
{
    Link* tempPtr = head->next;
    while (tempPtr != nullptr)
    {
        std::cout << "(" << tempPtr->element.key << "," << tempPtr->element.name << ")";
        tempPtr = tempPtr->next;
        if (tempPtr != nullptr) cout << ",";
    }
}

class Dictionary
{
    private:
        LList** H;
        int cnt;
        int hash(int key)
        {
            return key % 10;
        }
    public:
        Dictionary()
        {
            cnt = 0;
            H = new LList*[10];            
            for (int i = 0; i < 10; i++)
            {
                H[i] = new LList;
            }
        }
        LList* search(int key)
        {
            int h = hash(key);
            if (H[h]->count(key) > 0) return H[h];
            else return nullptr;
        }
        void insert(string n, int key)
        {
            int h = hash(key);
            if (search(key) != nullptr) return;
            H[h]->append(key, n);
            cnt++;
        }
        void remove(int key)
        {
            LList* keyList = search(key);
            if (keyList == nullptr) return;
            keyList -> moveToStart();
            while (keyList -> peekCurrPtr() != nullptr)
            {

                if (keyList->peekCurrPtr()->element.key == key)
                {
                    keyList -> remove();
                    cnt--;
                    return;
                }
                else
                {
                    keyList -> next();
                }
            }
        }
        int getSize() {return cnt;}
        void display()
        {
            for (int i = 0; i < 10; i++)
            {
                cout << i << ":";
                H[i]->display();
                cout << endl;
            }
        }
};

int main()
{
    int c;
    cin >> c;
    for (int i = 1; i<=c; i++)
    {
        cout << "caso " << i << ":" << endl;
        int n;
        cin >> n;
        cin.ignore();
        Dictionary dict;
        for (int x = 0; x < n; x++)
        {
            string comando; 
            getline(cin, comando);
            if (comando.substr(0, 3) == "add")
            {
                int firstSpace = 3;  // after "add"
                int secondSpace = comando.find(' ', firstSpace + 1);
                int chave = stoi(comando.substr(firstSpace + 1, secondSpace - firstSpace - 1));
                string nome = comando.substr(secondSpace + 1);
                dict.insert(nome, chave);
            }
            else if (comando.substr(0, 3) == "del")
            {
                int chave = stoi(comando.substr(4, 3));
                dict.remove(chave);
            }
        }
        cout << "alpha = " << dict.getSize() << "/10" <<endl;
        dict.display();
    }
}