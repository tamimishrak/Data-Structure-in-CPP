#include<iostream>

using namespace std;

class Queue{
    private:
        int rear;
        int front;
        int size;
        int *Q;
    public:
        Queue(){
            rear=front=-1;
            size = 10;
            Q = new int[size];
        }
        Queue(int size){
            rear=front=-1;
            this->size = size;
            Q = new int[this->size];
        }
        void enque(int x);
        int deque();
        void Display();
        bool isEmpty();
};

void Queue::enque(int x){
    if(rear==size-1){
        cout<<"Queue Full";
    }else{
        rear++;
        Q[rear] = x;
    }
}

int Queue::deque(){
    int x;
    if(front==rear){
        cout<<"Queue is empty";
    }else{
        x = Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display(){
    for(int i = front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
}

bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}

int main(){
    Queue q(10);

    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.Display();

    return 0;
}