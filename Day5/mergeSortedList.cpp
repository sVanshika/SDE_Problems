#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value, node* temp){
        data=value;
        next=temp;
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

node* merge(node* l1, node* l2){

    display(l1);
    display(l2);

    node* result = new node(0, NULL);
    node* temp = result;
    
    cout<<"started"<<endl;

    while(l1!=NULL || l2!=NULL){
        node* newNode = new node(0,NULL);
        cout<<"l1:"<<l1->data<<endl;
        cout<<"l2:"<<l2->data<<endl;

        if(l1->data < l2->data){
            cout<<"l1"<<endl;
            newNode->data = l1->data;
            l1 = l1->next;   
        }
        else{
            cout<<"l2"<<endl;
            newNode->data = l2->data;
            l2 = l2->next;
        }
        temp->next = newNode;
        temp=temp->next;
        cout<<"**newNode:"<<newNode->data<<endl;
    }

    cout<<"out"<<endl;
    
    while(l1!=NULL){
        node* newNode;
        newNode->data = l1->data;
        l1 = l1->next;
        temp->next = newNode;
        temp=temp->next;
        cout<<"newNode:"<<newNode->data<<endl;
    }
    while(l2!=NULL){
        node* newNode;
        newNode->data = l2->data;
        l2 = l2->next;
        temp->next = newNode;
        temp=temp->next;
        cout<<"newNode:"<<newNode->data<<endl;
    }
    return result->next;
}

int main(){
    node* l1 = new node(1,NULL);
    node* a = new node(3, NULL);
    node* b = new node(5, NULL);

    l1->next = a;
    a->next = b;

    node* l2 = new node(4, NULL);
    node* p = new node(6, NULL);
    node* q = new node(8, NULL);
    node* r = new node(10, NULL);

    l2->next = p;
    p->next = q;
    q->next = r;

    display(l1);
    display(l2);
    display(merge(l1, l2));
}