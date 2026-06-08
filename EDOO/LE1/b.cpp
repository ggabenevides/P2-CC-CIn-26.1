#include <iostream>

class Coach 
{
    public:
        int element;
        Coach* next;
        Coach(const int& e = 0, Coach* n = nullptr)
        {
            element = e;
            next = n;
        }
};

class Train
{
    private: 
        Coach* top;
        int size;
    public:
        Train(int s = 0)
        {
            top = new Coach(); // dummy head node
            top->next = nullptr; // initialize to nullptr
            size = 0; // let push increment the size naturally
            
            if (s != 0) // loaded stack for incoming train (N down to 1, so 1 is at the top)
            {
                for (int i = s; i > 0; i--)
                {
                    this->push(i);
                }
            }
        }
        
        ~Train()
        {
            clear();
            delete top;
        }
        
        void clear()
        {
            while(size != 0)
            {
                pop();
            }
        }
        
        void push(int e)
        {
            top->next = new Coach(e, top->next);
            size++;
        }
        
        int pop()
        {
            if (size == 0) return -1; 
            Coach* temp = top->next; 
            top->next = top->next->next; 
            size--; 
            int value = temp->element;
            delete temp;
            return value;
        }
        
        bool isEmpty() { return size == 0; }
        
        int peekFrontElement() 
        {
            if (size == 0) return -1;
            return top->next->element;
        }    
};

int main()
{
    int n;
    while (std::cin >> n && n != 0)
    {
        while (true)
        {
            int* target = new int[n];
            std::cin >> target[0];
            
            // 0 at the start of a line means the end of this block of permutations
            if (target[0] == 0) 
            {
                delete[] target;
                std::cout << "\n"; 
                break;
            }
            
            // read the rest of the permutation line
            for (int i = 1; i < n; i++) 
            {
                std::cin >> target[i];
            }
            
            Train incoming(n); // 1, 2, ..., n (with 1 at the top)
            Train station;     // empty station stack
            bool possible = true;
            
            // process each coach in the target permutation
            for (int i = 0; i < n; i++)
            {
                int currentTarget = target[i];
                
                // if the station has the coach we need on top, just let it leave
                if (!station.isEmpty() && station.peekFrontElement() == currentTarget)
                {
                    station.pop();
                }
                else
                {
                    // otherwise, move coaches from incoming to station until we find it
                    while (!incoming.isEmpty() && incoming.peekFrontElement() != currentTarget)
                    {
                        station.push(incoming.pop());
                    }
                    
                    // if we found it at the front of incoming, skip pushing it and just consume it
                    if (!incoming.isEmpty() && incoming.peekFrontElement() == currentTarget)
                    {
                        incoming.pop();
                    }
                    else
                    {
                        // if it's not in the station and not in incoming, it's impossible
                        possible = false;
                        break;
                    }
                }
            }
            
            if (possible)
                std::cout << "Yes\n";
            else
                std::cout << "No\n";

            delete[] target;
        }
    }
    return 0;
}