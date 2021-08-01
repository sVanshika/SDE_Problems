#include <iostream>
using namespace std;

#define SIZE 100

class StackArray{
    public:
        int arr[SIZE] = {0};
        int top = -1;
        bool push(int value);
        int pop();
        int peek();
        bool isEmpty();
        void display();
};

bool StackArray::push(int value){
    if(top >= SIZE-1){
        cout << "StackArray Overflow" << endl;
        return false;
    }
    arr[++top] = value;
    // cout << "Pushed" << endl;
    return true;
}

int StackArray::pop(){
    if(top == -1){
        cout << "StackArray Underflow" << endl;
        return -1;
    }
    int value = arr[top];
    arr[top] = 0;
    top--;
    cout << "Popped" << endl;
    return value;
}

int StackArray::peek(){
    if(top == -1)
        return -1;
    return arr[top];
}

bool StackArray::isEmpty(){
    if(top == -1) 
        return true;
    else 
        return false;
}

void StackArray::display(){
    cout << "StackArray: ";
    for(int i=0; i<SIZE, arr[i]!=0; i++){
        cout << arr[i] << ",";
    }
    cout<<endl;
}