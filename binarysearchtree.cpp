#include<iostream>

using namespace std;

//defining node for linking
class Node{
    public: 
        int val;
        Node *right;
        Node *left; 
};

//defining tree class
class BinarySearchTree{
    private:
        Node *root;
    public:
        BinarySearchTree(){ root = nullptr; };
        Node *getRoot(){ return root; };
        void insert(int k);
        void inOrder(Node *p);
        Node* searchValue(int k); 
};

void BinarySearchTree::insert(int k){
    Node *t = root;
    Node *p, *r;
    
    if(root==nullptr){
        p = new Node;
        p->val = k;
        p->left = nullptr;
        p->right = nullptr;
        root = p;
        return;
    }

    while(t!=nullptr){
        r = t;
        if(k < t->val){
            t = t->left;
        } else if(k > t->val){
            t = t->right;
        } else {
            return;
        }
    }

    p = new Node;
    p->val = k;
    p->left = nullptr;
    p->right = nullptr;

    if(k < r->val){
        r->left = p;
    } else {
        r->right = p;
    }
}

void BinarySearchTree::inOrder(Node *p){
    if(p){
        inOrder(p->left);
        cout<<p->val<<" ";
        inOrder(p->right);
    }
}

Node* BinarySearchTree::searchValue(int k){
    Node *t = root;

    while(t!=nullptr){
        if(k == t->val){
            return t;
        } else if(k < t->val){
            t = t->left;
        } else if(k > t->val){
            t = t->right;
        }
    }

    return nullptr;
}

int main(){
    BinarySearchTree t;
    
    t.insert(10);
    t.insert(5);
    t.insert(30);
    t.insert(15);
    t.insert(7);
    t.insert(20);
    t.insert(8);
    t.insert(3);

    cout<<"In Order: ";
    t.inOrder(t.getRoot());

    Node* found = t.searchValue(2); 
    
    if(found!=NULL) cout<<"\nThe value is: "<<found->val;
    else cout<<"\nThe value not found";

    return 0;
}