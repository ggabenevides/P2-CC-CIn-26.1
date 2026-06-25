#include <iostream>
#include <string>
using namespace std;

class Node
{
    public:
        int key; //in this case is also the element bc this is a simple integer bst
        Node *left, *right;
        Node (int k)
        {
            key = k;
            left = right = nullptr;
        }
};

class Tree
{
    private:
        Node* root;
        int nodecount;   
        
        // helper functions 
        int findhelp (Node* r, int k)
        {
            if (r == nullptr) return -1;
            if (r->key == k) return k;
            if (r->key > k) return findhelp(r->left, k);
            else return findhelp(r->right, k);
        }
        Node* inserthelp(Node* r, int k)
        {
            if (r == nullptr) 
            {
                Node* temp = new Node(k);
                return temp;
            }
            if (r->key > k)
            {
                r->left = inserthelp(r->left, k);
            }
            else
            {
                r->right = inserthelp(r->right, k);
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
        Node* removehelp(Node* r, int k)
        {
            if (r == nullptr) return nullptr;
            if (r->key > k) r->left = removehelp(r->left, k);
            else if (r->key < k) r->right = removehelp(r->right, k);
            else
            {
                if (r->left == nullptr) return r->right;
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
        void inorder_helper(const Node* r) 
        {
            if (r != nullptr) 
            {
                inorder_helper(r->left);  
                cout << r->key << " "; 
                inorder_helper(r->right);
            }
        }
        void preorder_helper(const Node* r) 
        {
            if (r != nullptr) 
            {
                cout << r->key << " "; 
                preorder_helper(r->left);  
                preorder_helper(r->right);
            }
        }
        void posorder_helper(const Node* r) 
        {
            if (r != nullptr) 
            {
                posorder_helper(r->left);  
                posorder_helper(r->right);
                cout << r->key << " "; 
            }
        }
    public:
        Tree()
        {
            root = nullptr;
            nodecount = 0;
        }
        int find (int k)
        {
            return findhelp(root, k);
        }
        void insert (int k)
        {
            root = inserthelp (root, k);
            nodecount++;
        }
        int remove(int k)
        {
            int temp = findhelp(root, k);
            if (temp != -1)
            {
                root = removehelp(root, k);
                nodecount--;
            }
            return temp;
        }
        void preorder() // with the task being printing the root's key
        {
            preorder_helper(root);
        }
        void inorder() // with the task being printing the root's key
        {
            inorder_helper(root);
        }
        void posorder() // with the task being printing the root's key
        {
            posorder_helper(root);
        }
};

int main()
{
    Tree t;
    int opcount;
    cin >> opcount;
    cin.ignore();
    for (int i = 0; i < opcount; i++)
    {
        string operation;
        getline(cin, operation);
        if (operation.find("insert") != string::npos)
        {
            int key = stoi(operation.substr(7));
            t.insert(key);
        }
        else if (operation.find("pre") != string::npos)
        {
            t.preorder();
            cout << endl;
        }
        else if (operation.find("pos") != string::npos)
        {
            t.posorder();
            cout << endl;
        }
        else if (operation.find("in") != string::npos)
        {
            t.inorder();
            cout << endl;
        }
    }
}