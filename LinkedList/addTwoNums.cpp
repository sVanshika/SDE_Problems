#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data=value;
        next=NULL;
    }
};

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

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* addTwoNumbers(node* head1, node* head2){

    node* result = new node(0);
    node* temp = result;
    node* temp1 = head1;
    node* temp2 = head2;
    int sum=0, carry=0;

    while(temp1!=NULL || temp2!=NULL || carry!=0){
        sum=0;
        if(temp1!=NULL){
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if(temp2!=NULL){
            sum += temp2->data;
            temp2 = temp2->next;
        }
        sum += carry;
        carry = sum/10;
        sum = sum%10;
        node* newNode = new node(sum);
        temp->next = newNode;
        temp = temp->next;
    }
    return result->next;

    // int num1=0, num2=0, x=1;
    // node* temp = head1;
    // while(temp!=NULL){
    //     num1 = (temp->data)*x + num1;
    //     x *= 10;
    //     temp = temp->next;
    // }

    // temp=head2;
    // x=1;
    // while(temp!=NULL){
    //     num2 = (temp->data)*x + num2;
    //     x *= 10;
    //     temp = temp->next;
    // }

    // cout<<"num1:"<<num1<<" num2:"<<num2<<endl;

    // int sum = num1+num2;
    // node* result = NULL;
    
    // if(sum == 0){
    //     insertAtTail(result, 0);
    // }
    // else{
    //     while(sum!=0){
    //         insertAtTail(result, (sum%10));
    //         sum /= 10;
    //     }
    // }

    return result;
    
}

int main(){
    node* head1 = NULL;
    insertAtTail(head1, 2);
    insertAtTail(head1, 4);
    insertAtTail(head1, 3);

    display(head1);

    node* head2 = NULL;
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    insertAtTail(head2, 7);
    insertAtTail(head2, 9);

    display(head2);

    display(addTwoNumbers(head1, head2));

    return 0;
}
    
