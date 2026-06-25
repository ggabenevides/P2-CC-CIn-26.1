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
        void inorder_helper(Node* r, bool& first)
        {
            if (r != nullptr)
            {
                inorder_helper(r->left, first);
                if (!first) cout << " ";
                cout << r->key;
                first = false;
                inorder_helper(r->right, first);
            }
        }
        void preorder_helper(Node* r, bool& first)
        {
            if (r != nullptr)
            {                
                if (!first) cout << " ";
                cout << r->key;
                first = false;
                preorder_helper(r->left, first);
                preorder_helper(r->right, first);
            }
        }
        void posorder_helper(Node* r, bool& first)
        {
            if (r != nullptr)
            {
                posorder_helper(r->left, first);
                posorder_helper(r->right, first);                
                if (!first) cout << " ";
                cout << r->key;
                first = false;
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
            bool first = true;
            preorder_helper(root, first);
        }
        void inorder() // with the task being printing the root's key
        {
            bool first = true;
            inorder_helper(root, first);
        }
        void posorder() // with the task being printing the root's key
        {
            bool first = true;
            posorder_helper(root, first);
        }
};

int main()
{
    Tree t;  
    int count;
    cin >> count;
    int element;
    for (int i = 0; i < count; i++)
    {
        cin >> element;
        t.insert(element);
    }
    cout << "Pre order : ";
    t.preorder();
    cout << endl;
    cout << "In order  : ";
    t.inorder();
    cout << endl;
    cout << "Post order: ";
    t.posorder();
    cout << endl;
}