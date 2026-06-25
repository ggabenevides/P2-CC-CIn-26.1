#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
    public:
        char key; 
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
        char findhelp (Node* r, char k)
        {
            if (r == nullptr) return ' ';
            if (r->key == k) return k;
            if (r->key > k) return findhelp(r->left, k);
            else return findhelp(r->right, k);
        }
        Node* inserthelp(Node* r, char k)
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
        Node* removehelp(Node* r, char k)
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
                cout << r->key; 
                inorder_helper(r->right);
            }
        }
        void preorder_helper(const Node* r) 
        {
            if (r != nullptr) 
            {
                cout << r->key; 
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
                cout << r->key; 
            }
        }

    public:
        Tree()
        {
            root = nullptr;
            nodecount = 0;
        }
        char find (char k)
        {
            return findhelp(root, k);
        }
        void insert (char k)
        {
            root = inserthelp (root, k);
            nodecount++;
        }
        char remove(char k)
        {
            char temp = findhelp(root, k);
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
    string line;
    vector<string> stages;

    while (getline(cin, line)) {
        if (line == "$" || line == "*") {
            Tree t;
            for (int i = stages.size() - 1; i >= 0; i--)
                for (char c : stages[i])
                    t.insert(c);
            t.preorder();
            cout << "\n";
            stages.clear();
            if (line == "$") break;
        } else {
            stages.push_back(line);
        }
    }

    return 0;
}