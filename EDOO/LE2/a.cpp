    #include <string>
    #include <iostream>
    #include <cmath>
    using namespace std;

    class Dictionary
    {
        private:
            int maxSize;
            int count;
            string* H;
            int hash(string key)
            {
                int sum = 0;
                for (int i = 0; i < key.length(); i++)
                {
                    sum += key[i]*(i+1);
                }
                return (19 * sum) % 101;
            }
        public:
            Dictionary(int size)
            {
                maxSize = size;
                count = 0;
                H = new string[maxSize];
                for (int i = 0; i < maxSize; i++)
                {
                    H[i] = " ";
                }
            }
            ~Dictionary() {delete[] H;}
            int search(const string& key) 
            {
                int h0 = hash(key);
                // j=0: check base position
                if (H[h0] == key) return h0;
                if (H[h0] == " ") return -1;  

                // j=1..19: probe
                for (int j = 1; j <= 19; j++) 
                {
                    int h = (h0 + j*j + 23*j) % 101;
                    if (H[h] == key) return h;
                    if (H[h] == " ") return -1;  
                }
                return -1;
            }
            void insert(string& key)
            {
                if (search(key) != -1) return;  // already exists

                int h0 = hash(key);
                int probes = 0;

                // base slot (j=0)
                if (H[h0] == " " || H[h0] == "*") 
                {
                    H[h0] = key;
                    count++;
                    return;
                }
                probes++;

                // probe j=1..19 (stop after 20 examined entries total)
                for (int j = 1; j <= 19 && probes < 20; j++, probes++) {
                    int h = (h0 + j*j + 23*j) % 101;
                    if (H[h] == " " || H[h] == "*") {
                        H[h] = key;
                        count++;
                        return;
                    }
                }
            }
            void remove(string& key)
            {
                int h = search(key);
                if (h == -1) return;
                H[h] = "*";
                count--;
            }
            int getCount() {return count;}
            void display()
            {
                for (int i = 0; i < maxSize; i++)
                {
                    if (H[i] != " " && H[i] != "*")
                    {
                        cout << i << ":" << H[i] << endl; 
                    }
                }
            }
    };

    int main()
    {
        int testcases, opCount;
        cin >> testcases;
        for (int i = 0; i < testcases; i++)
        {
            cin >> opCount;
            cin.ignore();
            Dictionary dict(1000);
            for (int j = 0; j < opCount; j++)
            {
                string comando;
                getline(cin, comando);
                string operation = comando.substr(0,3);
                string element = comando.substr(4);

                if (operation == "ADD")
                {
                    dict.insert(element);
                }
                else if (operation == "DEL")
                {
                    dict.remove(element);
                }
            }
            cout << dict.getCount() << endl;
            dict.display();
        }
    }