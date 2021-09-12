#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtTail(node* &head, int value){
    node* newNode = new node(value);
    if(head == NULL)
        head=newNode;
    else{
        node* temp = head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next = newNode;
    }
}

void insertAtHead(node* &head, int value){
    node* newNode = new node(value);
    if(head == NULL)
        head=newNode;
    else{
        newNode->next = head;
        head = newNode;
    }
}

void insertBeforeValue(node* &head, int before, int value){
    node* temp = head;
    if(head->data == before)
        insertAtHead(head, value);
    else{
        node* newNode = new node(value);
        while((temp->next)->data != before)
            temp=temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


int main(){
    node* head = NULL;
    insertAtTail(head, 101);
    insertAtTail(head, 102);
    insertAtTail(head, 103);
    insertAtHead(head, 100);
    insertBeforeValue(head, 103, 99);
    display(head);
}