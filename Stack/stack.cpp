/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

#include "stackArray.h"
#include "stackLinkedList.h"

int main(){
    // class StackArray stack_array;
    // stack_array.push(10);
    // stack_array.push(20);
    // stack_array.push(30);
    // stack_array.pop();
    // cout << "Empty: " << stack_array.isEmpty() << endl;
    // cout << "Peek: " << stack_array.peek() << endl;
    // stack_array.push(40);
    // stack_array.display(); 

    class StackLinkedList stack_linkedlist;
    stack_linkedlist.push(3);
    stack_linkedlist.push(4);
    stack_linkedlist.push(5);
    stack_linkedlist.push(6);
    stack_linkedlist.push(7);
    stack_linkedlist.push(8);
    stack_linkedlist.display();
    cout<<"Popped:"<<stack_linkedlist.pop()<<endl;
    stack_linkedlist.push(9);
    stack_linkedlist.push(10);
    stack_linkedlist.display();
    cout<<"Peek:"<<stack_linkedlist.peek()<<endl;
    
    return 0;
}