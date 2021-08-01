#include <iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int v, ListNode* n){
        val = v;
        next = n;
    }
};

class StackLinkedList{
    public:
    ListNode* head = NULL;
    ListNode* top = NULL;
    bool push(int value);
    int pop();
    int peek();
    bool isEmpty();
    void display();
};

bool StackLinkedList::push(int value){
    ListNode* newNode = new ListNode(value, NULL);
    if(top == NULL){
        head = newNode;
    }
    else{
        ListNode* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    top = newNode;
    return true;
}

int StackLinkedList::pop(){
    if(head == NULL){
        //empty stack
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    if(head->next == NULL){
        //only 1 element exists
        cout<<"Only 1 element exists"<<endl;
        int value = top->val;
        head = NULL;
        top = NULL;
        return value; 
    }
    ListNode* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    int value = temp->next->val;
    temp->next = NULL;
    top = temp;
    return value;
}

int StackLinkedList::peek(){
    if(top == NULL)
        return -1;
    return top->val;
}

void StackLinkedList::display(){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

