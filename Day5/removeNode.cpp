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

node* removeNthFromEnd(node* &head, int n){
    
    if(head->next == NULL) //only 1 node is present
        head=NULL;
    else
    {
        int total=0;
        node* temp = head;
        while(temp!=NULL){
            total++;
            temp=temp->next;
        }

        if(n == total){
            cout<<"remove first node"<<endl;
            temp=head;
            head=head->next;
            delete(temp);
        }
        else{
            temp=head;
            for(int i=1; i<(total-n); i++)
                temp=temp->next;
            temp->next = temp->next->next; 
        }
    }
    return head;
}

node* removeNthFromEndOptimal(node* &head, int n){
    node* temp = new node(0, head);
    node* slow = temp;
    node* fast = temp;
    
    for(int i=0; i<n; i++)
        fast=fast->next;

    while(fast->next != NULL){
        slow=slow->next;
        fast=fast->next;
    }

    slow->next = slow->next->next;

    return temp->next;
    
}
int main(){
    // node* fifth = new node(11, NULL);
    // node* fourth = new node(9, fifth);
    // node* third = new node(7, fourth);
    //node* second = new node(4, NULL);
    node* head = new node(1, NULL);

    display(head);

    //display( removeNthFromEnd(head, 2) );

    display( removeNthFromEndOptimal(head, 1) );
}