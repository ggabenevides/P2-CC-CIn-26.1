#include <iostream>
#include <string>

//ferry: stack of cars
//queue of cars waiting for ferry at each side of river
//each car as a length in meters
//ferry has a maximum length and a current side of river

class Car
{
    public:
        int length;
        Car* next;
        Car(int l, Car* n = nullptr)
        {
            length = l;
            next = n;
        }
};

class Queue 
{
    private: 
        Car *front, *rear;
        int size;
    public: 
        Queue()
        {
            front = rear = new Car(0); //head node
            size = 0;
        }
        ~Queue()
        {
            clear();
            delete front;
        }
        void clear()
        {
            while (size != 0)
            {
                dequeue();
            }
        }
        void enqueue(int l)
        {
            rear->next = new Car(l, nullptr); //create new link with value and assign former rear element's next ptr to it
            rear = rear->next; // move rear pointer to new element
            size++; //update size
        }
        int dequeue() {
            if (size == 0) return -1; // guard
            Car* temp = front->next;  // first real node
            int value = temp->length;
            front->next = temp->next;
            if (front->next == nullptr) rear = front; // list is now empty
            delete temp;
            size--;
            return value;
        }
        int getSize(){return size;}
        int peekFrontElement() {return front->next->length;}
};

class Ferry
{
    private: 
        Car* top;
        int maxLength, currLength; //in cm 
        std::string currSide; //left or right
    public:
        Ferry(int maxL)
        {
            top = new Car(0);
            currLength = 0;
            maxLength = maxL;
            currSide = "left";
        }
        ~Ferry()
        {
            clear();
            delete top;
        }
        void clear()
        {
            while(currLength !=0)
            {
            pop();
            }
        }
        void crossRiver()
        {
            currSide = (currSide == "left") ? "right" : "left"; //update side after unloading
        }
        void push(int e)
        {
            top->next = new Car(e, top->next);
            currLength += e; //assume validity checking outside this method
        }
        int pop()
        {
            if (currLength == 0) return -1; //guard
            Car* temp = top->next; //temp var to free storage
            top->next = top->next->next; //reassign pointer
            currLength -= temp->length; //update length
            int value = temp->length;
            delete temp;
            return value;
        }
        bool isFull(){return currLength == maxLength;}
        bool validAddition(int l){return currLength + l <= maxLength;}
        const std::string getSide(){return currSide;}
};

// main behavior:
    //init two queues OK
    //input: number of test cases OK
    //test case loop OK
    //input: length of current ferry, number of cars it will have to transport OK
    //init ferry with length OK
    //enqueue loop (size is number of cars from input) OK
    // if left enqueue to left queue, if right enqueue to right queue OK
    //exit  enqueue loop OK
    //start dequeueing process and store number of times ferry has to cross river
    //while lqueue and rqueue are not empty
    //dequeue has to evaluate if it is possible to stack the car
    //stack is full: clear it and increment; change current side (if left ->right etc)
    //check if current queue (left or right depending on recent crossing) still has cars, if so stack them and cross (change side)
    //else check if other side has cars, if so cross it again, else exit loop
    //ouput number of total crossings

int main()
{
    int caseCount;
    std::cin >> caseCount;

    for (int i = 1; i <= caseCount; i++)
    {
        Queue leftQueue, rightQueue;

        int ferryLen, carCount;
        std::cin >> ferryLen >> carCount;
        ferryLen *= 100;

        Ferry f(ferryLen);

        for (int j=0; j<carCount; j++)
        {
        int carLen;
        std::string carSide;
        std::cin >> carLen >> carSide;

        if (carSide == "left") {leftQueue.enqueue(carLen);}
        else if (carSide == "right") {rightQueue.enqueue(carLen);}
        }
        int crossings = 0;
        while (leftQueue.getSize() != 0 || rightQueue.getSize() != 0)
        {
            Queue* currentQueue = (f.getSide() == "left") ? &leftQueue : &rightQueue;
            
            // load cars from the current bank until full or no more cars
            while (currentQueue->getSize() != 0 && f.validAddition(currentQueue->peekFrontElement()))
            {
                f.push(currentQueue->dequeue());
            }
            
            // travel to the other side (unloads cars and switches banks)
            f.clear(); 
            f.crossRiver();
            crossings++; 
        }
        
        std::cout << crossings << std::endl;
    }
    return 0;
}