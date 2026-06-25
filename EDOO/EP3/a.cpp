#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
        int key;
        Node *left, *right;
        Node (int k) :key(k), left(nullptr), right(nullptr) {}
};

class Tree
{
    private:
        Node* root;
        int nodecount;
        int findhelper(Node* r, int k)
        {
            if (r == nullptr) return -1;
            if (r->key > k) return findhelper(r->left, k);
            else if (r->key == k) return r->key;
            else return findhelper(r->right, k);
        }
        Node* inserthelper(Node* r, int k)
        {
            if (r == nullptr) 
            {
                Node* temp = new Node(k);
                return temp;
            }
            if (r->key > k) r->left = inserthelper(r->left, k);
            else r->right = inserthelper(r->right, k);
            return r;
        }
        Node* removehelper(Node* r, int k)
        {
            if (r == nullptr) return nullptr;
            if (r->key > k) r->left  = removehelper(r->left,  k);
            else if (r->key < k) r->right = removehelper(r->right, k);
            else if (r->right != nullptr && r->right->key == k)  // tem um mais novo na direita
                 r->right = removehelper(r->right, k);
            else  // esse é o mais antigo, remove
            {
                if (r->left == nullptr)  return r->right;
                else if (r->right == nullptr) return r->left;
                else
                {
                    Node* temp = getmin(r->right);
                    r->key = temp->key;
                    r->right = deletemin(r->right);
                }

            }
            return r;
        }
        Node* getmin(Node* r)
        {
            if (r->left == nullptr) return r;
            return getmin(r->left);
        }
        Node* deletemin(Node* r)
        {
            if (r->left == nullptr) return r->right;
            r->left = deletemin(r->left);
            return r;
        }
        void posorderhelper(const Node* r)
        {
            if (r != nullptr)
            {
                posorderhelper(r->left);
                posorderhelper(r->right);
                cout << r->key << endl;
            }
        }
    public:
        Tree()
        {
            root = nullptr;
            nodecount = 0;
        }
        int find(int k)
        {
            return findhelper(root, k);
        }
        void insert(int k)
        {
            root = inserthelper(root, k);
            nodecount++;
        }
        int remove(int k)
        {
            int temp = findhelper(root, k);
            if (temp != -1) //se não existe ignora
            {
                root = removehelper(root, k);
                nodecount--;
            }
            return temp;
        }
        void posorder()
        {
            posorderhelper(root);
        }
        int getCount() {return nodecount;}
};

int main()
{
    Tree t;
    int count;
    cin >> count;
    cin.ignore();
    string operation;
    for (int i = 0; i < count; i++)
    {
        getline(cin, operation);
        if (operation.find("ins") != string::npos) 
        {
            int key = stoi(operation.substr(4));
            t.insert(key);
        }
        else if (operation.find("rem") != string::npos)
        {
            int key = stoi(operation.substr(4));
            t.remove(key);
        }
    }
    cout << t.getCount() << endl;
    t.posorder();
}