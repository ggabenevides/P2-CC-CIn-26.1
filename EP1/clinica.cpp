#include <iostream>
#include <string>
#include <cctype>

// string link
class Paciente
{
    public:
        std::string element;
        Paciente* next;
        Paciente(std::string e = " ", Paciente* p = nullptr);
        ~Paciente(){};

};

//string queue
class Clinica
{
    private:
        Paciente *front, *rear;
        int size;
    public:
        friend class EmptyQueueException;
        friend std::ostream& operator<<(std::ostream& os, Clinica& c);
        Clinica();
        ~Clinica();
        void clear();
        void enqueue(std::string& e);
        void encaixe(std::string& e, int pos);
        void dequeue();
        int length(){return size;}
        void display();
};

Paciente::Paciente(std::string e, Paciente* p)
{
    element = e;
    next = p;
}

Clinica::Clinica()
{
    front = rear = new Paciente(); // init with header node 
    size = 0;
}

Clinica::~Clinica()
{
    clear();
}

void Clinica::clear()
{
    while (rear->next != nullptr)
    {
        dequeue();
    }
}

void Clinica::dequeue()
{
    if (size == 0) return; //empty queue
    if (front->next == nullptr) rear = front; // 1 element  
    Paciente* temp = front; // use temp var to free storage
    front = front->next;// reassign pointer
    //front->next = front->next->next; 
    delete temp; // free storage
    size--; // update size
}

void Clinica::enqueue(std::string& e)
{
    rear->next = new Paciente(e, nullptr); //create new link with value and assign former rear element's next ptr to it
    rear = rear->next; // move rear pointer to new element
    size++; //update size
}

void Clinica::encaixe(std::string& e, int pos)
{
    if (pos>size){
        enqueue(e);
    }
    else{
        Paciente* temp = front;
        int count = 1;
        while (count != pos)
        {
            temp = temp->next;
            count++;
        }
        temp->next = new Paciente(e, temp->next);
        size++;
    }
    
}

void Clinica::display()
{
    if (size == 0)
    {
        std::cout << "---" << std::endl;
        
    }
    else
    {
        Paciente* temp = front->next;
        int count = 0;
        while (count != size)
        {
            std::cout << temp->element;
            if (temp->next != nullptr)
            {
                std::cout << ", ";
            }
            temp = temp->next;
            count++;
        }
        std::cout << std::endl;
    }

}

int main()
{
    //instanciar fila
    Clinica fila;

    //pegar número de casos
    int caseCount;
    std::cin >> caseCount;

    for (int i = 1; i <= caseCount; i++)
    {
        std::cout << "caso " << i << ": \n";

        int opCount;
        std::cin >> opCount;

        for (int j = 0; j <= opCount; j++)
        {
            std::string operation;
            getline(std::cin, operation);
            std::string nome;

            if (operation.substr(0, 3) == "add")
            {
                try
                {
                    int pos = stoi(operation.substr(4, 1));
                    nome = operation.substr(6);
                    fila.encaixe(nome, pos);
                }
                catch(const std::exception& e)
                {
                    nome = operation.substr(4);
                    fila.enqueue(nome);
                }
            }
            else if (operation == "next")
            {
                fila.dequeue();
            }
            else if (operation == "status")
            {
                fila.display();
            }
        }
    }
    fila.clear();
}