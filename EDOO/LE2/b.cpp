#include <iostream>
#include <string>
using namespace std;

struct Entry
{
    string content;
    string translation;
    int state; // 0 for empty, 1 for used and 2 for deleted (doing this to avoid string constructor)
    Entry() : state(0) {}
};

class Dictionary
{
    private:
        int m;
        int cnt;
        Entry* H;
        int fold(const string& key) //stronger hash function to try to disperse elements more evenly
        {
            unsigned int hash = 5381;
            for (char c : key)
                hash = hash * 33 + c;
            return hash % m;
        }

    public:
        Dictionary(int size)
        {
            m = size;
            cnt = 0;
            H = new Entry[size];
        }
        ~Dictionary(){delete[] H;}
        int search(string key)
        {
            unsigned int h = fold(key);
            for (int i = 0; i < m; i++)
            {
                int pos = h % m;
                if (H[pos].state == 0) return -1; //empty state -> not found
                if (H[pos].state == 1 && H[pos].content == key) return pos;
                h = h * 1664525 + 1013904223; //pseudo random probing with constants
            }
            return -1;
        }
        void insert(string key, string translation)
        {
            unsigned int h = fold(key);
            if (cnt == m) return;
            if (search(key) != -1) return;
            for (int i = 0; i < m; i++)
            {
                int pos = h % m;
                if (H[pos].state == 0 || H[pos].state == 2)
                {
                    H[pos].content = key;
                    H[pos].translation = translation;
                    H[pos].state = 1;
                    cnt++;
                    return;
                }
                h = h * 1664525 + 1013904223;
            }
            cnt++;
        }
        void remove(string key)
        {
            int h = search(key);
            if (h == -1) return;
             H[h].state = 2; // deleted
            cnt--;
        }
        string getTranslation(int pos)
        {
            return H[pos].translation;
        }
};

int main()
{
    Dictionary dict(400000);
    string input;
    while (getline(cin, input))
    {
        if (input.empty()) continue;
        int spaceIndex = input.find(" ");
        if (spaceIndex != string::npos)
        {
            // dictionary entry
            string translation = input.substr(0, spaceIndex);
            string content = input.substr(spaceIndex + 1);
            dict.insert(content, translation);
        }
        else
        {
            // lookup word
            int translationPos = dict.search(input);
            if (translationPos == -1) cout << "eh" << endl;
            else cout << dict.getTranslation(translationPos) << endl;
        }
    }
}
