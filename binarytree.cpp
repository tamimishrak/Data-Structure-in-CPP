#include<iostream>

using namespace std;

//Node for creating Binary Tree
class Node{
    public: 
        int data;
        Node *lchild;
        Node *rchild;
};

class Queue{
    private:
        int front;
        int rear;
        int size;
        Node **Q;

    public:
        Queue(){
            rear=front=-1;
            size = 10;
            Q = new Node*[size];
        }
        Queue(int size){
            rear=front=-1;
            this->size = size;
            Q = new Node*[this->size];
        }
        void enqueue(Node *x);
        Node* dequeue();
        void Display();
        int isEmpty(){
            return front==rear;
        };
};

void Queue::enqueue(Node *x){
    if(rear==size-1){
        cout<<"Queue is full"<<endl;
    }else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue(){
    Node *x = NULL;
    if(rear==front){
        cout<<"Queue is empty"<<endl;
    }else {
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display(){
    for(int i=front+1; i<=rear; i++){
        cout<<Q[i]<<" ";
    }
}

// Defining Tree Class
class Tree{
    public:
        Node *root;
        Tree(){
            root = NULL;
        }
        void createTree();
        void preOrder(Node *p);
        void postOrder(Node *p);
        void inOrder(Node *p);
        void levelOrder(Node *p);
        int height(Node *p);
};

void Tree::createTree(){
    Node *p, *t;
    int x;
    Queue q(50);

    cout<<"Enter a value for root: ";
    cin>>x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty()){
        p = q.dequeue();

        cout<<"Enter a value for the left child of "<<p->data<<": ";
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter a value for the right child of "<<p->data<<": ";
        cin>>x;

        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p){
    if(p){
        preOrder(p->lchild);
        preOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }
}

int main(){
    Tree t;

    t.createTree();
    
    cout<<"Pre Order: ";
    t.preOrder(t.root);

    cout<<endl;

    cout<<"Post Order: ";
    t.postOrder(t.root);

    cout<<endl;

    cout<<"In Order: ";
    t.inOrder(t.root);


    return 0;
}