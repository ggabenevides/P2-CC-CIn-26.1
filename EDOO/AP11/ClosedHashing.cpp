#include <string>
#include <iostream>

class Dictionary
{
    private:

        int m;
        int cnt;
        std::string* H; //array of strings;
        int fold(std::string k)
        {
            int s = k.length();
            int sum = 0;
            for (int i = 0; i < s; i++)
            {
                sum += k[i];
            }
            return abs(sum % m);
        }

    public:

        Dictionary(int l)
        {
            m = l;
            cnt = 0;
            H = new std::string[m];
            for (int i = 0; i < m; i++)
            {
                H[i] = " ";
            }
        }

        ~Dictionary() 
        {
            delete[] H;
        }

        int search(std::string key)
        {
            int index = fold(key); //first index to check is hash function result
            for (int i = 0; i < m; i++) 
            {
                if (H[index] == " ") return -1; // stop at truly empty slot
                if (H[index] == key) return index; // found it
                index = (index + 1) % m; // skip over tombstones ("*") and collisions
            }
            return -1; // Table is full and element not found
        }

        void insert(std::string key)
        {
            int index = fold(key);

            if (search(key) != -1) return; //if element is already in dict nothing happens
            if (cnt == m) return;

            while (H[index] != " " && H[index] != "*")
            {
                index = (index + 1) % m;
            }

            H[index] = key;
            
            cnt++;
        }

        void remove(std::string key)
        {
            int index = search(key);
            if (index == -1) return; //if element is not in dict nothing happens
            else H[index] = "*"; //designated symbol for positions that have been used before
            cnt--;
        }
};

int main ()
{

    int m;
    std::cin >> m;
    Dictionary dict(m);
    std::cin.ignore();
    std::string comando("oi");

    while (true)
    {        
        getline(std::cin, comando);

        if (comando == "fim") 
        {
            break;
        }

        std::string operacao = comando.substr(0, 3);
        std::string key = comando.substr(4);

        if (operacao == "add")
        {
            dict.insert(key);
        }
        else if (operacao == "rmv")
        {
            dict.remove(key);
        }
        else if (operacao == "sch")
        {
            int index = dict.search(key);
            std::cout << key << " " << index << std::endl;
        }
    }
}