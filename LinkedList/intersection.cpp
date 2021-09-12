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

void display(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

ListNode* intersectionOptimal(ListNode* l1, ListNode* l2){
    int n1=0, n2=0;
    ListNode* temp1=l1;
    ListNode* temp2=l2;
    //finding size of l1
    while(temp1!=NULL){
        n1++;
        temp1=temp1->next;
    }
    //finding size of l2
    while(temp2!=NULL){
        n2++;
        temp2=temp2->next;
    }
    //cout<<"n1:"<<n1<<" n2:"<<n2<<endl;

    //considering size of l1 < size of l2
    if(n1>n2) swap(l2,l1);

    temp1=l1, temp2=l2;
    //moving temp2 to same starting point for temp1 and temp2
    for(int i=0; i<abs(n2-n1); i++)
        temp2=temp2->next;
    
    //cout<<temp2->val<<endl;
    while(temp1!=NULL || temp2!=NULL){
        //cout<<temp1->val<<","<<temp2->val<<endl;
        if(temp1 == temp2){
            break;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

    return temp1;

}

ListNode* intersectionOptimal_2(ListNode* l1, ListNode* l2){
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;

    while(true){
        cout<<temp1->val<<","<<temp2->val<<endl;
        if(temp1==NULL && temp2==NULL)
            break;
        else{
            if(temp1==NULL && temp2!=NULL) temp1=l2;
            if(temp1!=NULL && temp2==NULL) temp2=l1;
            if(temp1==temp2) break;
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
    }
    return temp1;
}

int main(){
    ListNode* l1 = new ListNode(1,NULL);
    ListNode* a = new ListNode(2, NULL);
    ListNode* b = new ListNode(8, NULL);
    ListNode* c = new ListNode(7, NULL);
    ListNode* d = new ListNode(6, NULL);

    l1->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    ListNode* l2 = new ListNode(12, NULL);
    ListNode* p = new ListNode(18, NULL);
    ListNode* q = new ListNode(11, NULL);
    ListNode* r = new ListNode(13, NULL);
    

    l2->next = p;
    p->next = q;
    q->next = r;
    r->next = b;
    b->next = c;
    c->next = d;

    display(l1);
    display(l2);
    cout<<intersectionOptimal(l1,l2)<<"\n"<<endl;
    cout<<intersectionOptimal_2(l1,l2)<<endl;
    return 0;
}