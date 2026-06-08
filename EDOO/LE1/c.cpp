#include <string>
#include <iostream>

class Character
{
    public:
        char element;
        Character* next; 
        Character(char elemval = '-', Character* nextval = nullptr)
        {
            element = elemval;
            next = nextval;
        }
};

class Sentence
{
    private:
        Character *head, *tail, *curr;
        bool empty;
        
    public:
        Sentence() // init with dummy node
        {
            curr = tail = head = new Character();
            empty = true;
        }
        
        ~Sentence()
        {
            clear(); 
        }
        
        void insert(char x)
        {
            curr->next = new Character(x, curr->next);
            if (tail == curr) tail = curr->next;
            curr = curr->next; 
            empty = false;
        }
        
        
        void moveToStart()
        {
            curr = head; 
        }
        
        void moveToEnd()
        {
            curr = tail;
        }
        
        void clear()
        {
            while (head != nullptr)
            {
                Character* temp = head;
                head = head->next;
                delete temp;
            }
            curr = tail = head = nullptr;
        }
        
        void display()
        {
            if (empty) return;
            Character* temp = head->next; // skip dummy node
            while (temp != nullptr)       
            {
                std::cout << temp->element;
                temp = temp->next;
            }
            std::cout << std::endl;
        }

        void reset()
        {
            clear();
            curr = tail = head = new Character();
            empty = true;
        }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c;
    Sentence s;
    
    while (std::cin.get(c))
    {
        if (c == '\n' || c == '\r') 
        {
            s.display();
            s.reset();
            continue;
        }
        
        if (c == '[')
        {
            s.moveToStart();
        }
        else if (c == ']')
        {
            s.moveToEnd();
        }
        else 
        {
            s.insert(c); // only insert actual text characters
        }
    }
    
    // print anything left if input didn't end on a newline
    s.display(); 
    return 0;
}