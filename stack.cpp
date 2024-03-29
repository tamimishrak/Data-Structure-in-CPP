#include<iostream>

using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *S;
    public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    bool isFull();
    bool isEmpty();
    void display();
    int topElement();
};

Stack::Stack(int size){
    this->size = size;
    top=-1;
    S = new int[size];
}

Stack::~Stack(){
    delete[] S;
}

void Stack::push(int x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    } else {
        top++;
        S[top] = x;
    }
}

int Stack::pop(){
    int x;
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
    } else {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::peek(int index){
    int x = -1;
    if(top-index+1 < 0 || top-index+1==size){
        cout<<"Invalid position"<<endl;
    } else {
        x = S[top-index+1];
    }
    return x;
}

bool Stack::isFull() {
    if (top == size-1){
        return true;
    }
    return false;
}

bool Stack::isEmpty() {
    if (top == -1){
        return true;
    }
    return false;
}

void Stack::display() {
    for (int i=top; i>=0; i--){
        cout<<S[i]<<" ";
    }
}

int Stack::topElement() {
    if (isEmpty()){
        return -1;
    }
    return S[top];
}

int main(){
    Stack st(5);

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.display();

     if(st.isFull()){
        cout<<"\nQueue is full"<<endl;
    }

    return 0;
}