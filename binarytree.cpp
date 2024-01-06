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

int main(){
    
    cout<<"Hello";
    cout<<"GG NO RE";
    return 0;
}