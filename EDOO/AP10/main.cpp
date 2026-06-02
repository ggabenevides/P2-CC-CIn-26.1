#include "stack.hpp"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //instanciar lista
    LStack lista;
    //entrada: número de cases
    int caseCount;
    cin >> caseCount;
    //loop 1: entrar no loop de operações e depois resetar lista
    for (int i = 1; i <= caseCount; i++)
    {
        //saída: printar inicialmente qual é o case
        cout << "Caso " << i << ":" << endl;
        //loop 2: tratamento de entrada das strings e operações de acordo com elas
        string operation("");
        while (operation != "end")
        {
            getline(cin, operation);
            if (operation.find("push") != std::string::npos)
            {
                int x = std::stoi(operation.substr(5));
                lista.push(x);
            }
            else if (operation.find("pop") != std::string::npos)
            {
                int x = std::stoi(operation.substr(4));
                int sum(0);
                for (int i = 0; i< x; i++)
                {
                    int temp = lista.pop();
                    sum += temp;
                }
                
                cout << sum << endl; //saída: toda vez que tiver pop, printar soma dos n números no topo da stack que foram removidos
            }
        }
        lista.clear();
    }
}