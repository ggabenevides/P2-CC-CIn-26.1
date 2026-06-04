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
            delete rear;
        }
        void clear()
        {
            while (rear->next != nullptr)
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
        int dequeue()
        {
            if (size == 0) return; //empty queue
            if (front->next == nullptr) rear = front; // 1 element  
            Car* temp = front; // use temp var to free storage
            int value = temp->length;
            front = front->next;// reassign pointer
            delete temp; // free storage
            size--; // update size
            return value;
        }
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
            currSide = ("left") ? "right" : "left"; //update side after unloading
        }
        void push(int& e)
        {
            top->next = new Car(e, top->next);
            currLength += e; //assume validity checking outside this method
        }
        int pop()
        {
            Car* temp = top->next; //temp var to free storage
            top->next = top->next->next; //reassign pointer
            currLength -= temp->length; //update length
            int value = temp->length;
            delete temp;
            return value;
        }
        bool isFull(){return currLength == maxLength;}
        bool validAddition(int& l){return currLength + l <= maxLength;}
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
    Queue leftQueue;
    Queue rightQueue;
    int caseCount;
    std::cin >> caseCount;
    std::cin.ignore();

    for (int i = 1; i <= caseCount; i++)
    {
        std::string caseInfo;
        getline(std::cin, caseInfo); //format example "20 4"

        //input treatment
        bool substr1complete = false;
        std::string substr1, substr2;

        for (char c : caseInfo)
        {
            if (c == ' ')
            {
                substr1complete = true;
            }
            else if (!substr1complete)
            {
                substr1 += c;
            }
            else if (substr1complete)
            {
                substr2 += c;
            }
        }

        int ferryLen = stoi(substr1)*10; //convert m to cm
        int carCount = stoi(substr2);

        Ferry f(ferryLen);

        for (int j=0; j<carCount; j++)
        {
            std::string currCar;
            getline(std::cin, currCar); //format example "2040 left"

            //input treatment
            bool substr1complete = false;
            std::string carLenStr, carSide;

            for (char c : currCar)
            {
                if (c == ' ')
                {
                    substr1complete = true;
                }
                else if (!substr1complete)
                {
                    carLenStr += c;
                }
                else if (substr1complete)
                {
                    carSide += c;
                }
            }

            int carLen = stoi(carLenStr);

            if (carSide == "left") {leftQueue.enqueue(carLen);}
            else if (carSide == "right") {rightQueue.enqueue(carLen);}
        }


    }
}