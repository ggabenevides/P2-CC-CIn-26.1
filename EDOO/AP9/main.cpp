//#include "listArray.hpp"
#include "listLink.hpp"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //instanciar lista
    //AList lista(20);
    LList lista;
    //entrada: número de cases
    int caseCount;
    cin >> caseCount;
    //loop 1: perguntar quantas operações vão ter nesse case, entrar no loop de operações e depois resetar lista
    for (int i = 1; i <= caseCount; i++)
    {
        //saída: printar inicialmente qual é o case
        cout << "Caso " << i << ":" << endl;
        int opCount;
        cin >> opCount;
        //loop 2: tratamento de entrada das strings e operações de acordo com elas
        for (int j = 0; j <= opCount; j++)
        {
            string operation;
            getline(cin, operation);
            if (operation.find("insert") != std::string::npos)
            {
                int lastIndex = operation.length() - 1;
                int x = operation[lastIndex];
                lista.insert(x);
            }
            else if (operation.find("count") != std::string::npos)
            {
                int lastIndex = operation.length() - 1;
                int x = operation[lastIndex];
                int xCount = lista.count(x);
                cout << xCount << endl; //saída: toda vez que tiver count, printar resultado do count()
            }
            else if (operation.find("remove") != std::string::npos)
            {
                int temp = lista.remove();
            }
            else if (operation.find("next") != std::string::npos)
            {
                lista.next();
            }
            else if (operation.find("prev") != std::string::npos)
            {
                lista.prev();
            }
            
        }
        lista.clear();
    }
   
    
    
    
}