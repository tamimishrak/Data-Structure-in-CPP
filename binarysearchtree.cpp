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
        Node* deleteValue(Node *p, int k);
        Node* inorderSuccessor(Node* p);
        Node* inorderPredecessor(Node *p);
        int height(Node *p);
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

int BinarySearchTree::height(Node *p){

    if(p==NULL){
        return 0;
    }

    int r = 0;
    int l = 0;

    l = height(p->left);
    r = height(p->right);

    if(l > r){
        return l+1;
    } else {
        return r+1;
    }
}

Node* BinarySearchTree::deleteValue(Node *p, int k){
    Node *q;

    if(p==nullptr){
        return nullptr;
    }

    if(p->left==nullptr && p->right==nullptr){
        if(p==root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if(p->val > k){
        p->left = deleteValue(p->left, k);
    } else if(p->val < k){
        p->right = deleteValue(p->right, k);
    } else {
        if(height(p->left) > height(p->right)){
            q = inorderPredecessor(p->left);
            p->val = q->val;
            p->left = deleteValue(p->left, q->val);
        } else {
            q = inorderSuccessor(p->right);
            p->val = q->val;
            p->right = deleteValue(p->right, q->val);
        }
    }

    return p;
}

Node* BinarySearchTree::inorderPredecessor(Node *p){
    while(p && p->right!=nullptr){
        p = p->right;
    }
    return p;
}

Node* BinarySearchTree::inorderSuccessor(Node *p){
    while(p && p->left!=nullptr){
        p = p->left;
    }
    return p;
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
    
    t.deleteValue(t.getRoot(),10);

    cout<<"In Order: ";
    t.inOrder(t.getRoot());

    Node* found = t.searchValue(5); 
    
    if(found!=NULL) cout<<"\nThe value is: "<<found->val;
    else cout<<"\nThe value not found";

    cout<<"\nHeight of the tree is "<<t.height(t.getRoot())<<endl;

    return 0;
}