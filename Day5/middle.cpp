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

//OPTIMAL -> Time: O(n/2) Space: O(1)
ListNode* middleNode(ListNode* head) {
        
    if(head->next == NULL) return head;
    else if(head->next->next == NULL) return head->next;
    else{
        ListNode* slow=head;
        ListNode* fast=head;
        while(true){
            //cout<<slow->val<<","<<fast->val<<endl;
            if(fast==NULL) break;
            else if(fast->next==NULL) break;
            else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return slow;
    }
}

int main(){
    ListNode* l1 = new ListNode(1,NULL);
    ListNode* a = new ListNode(2, NULL);
    ListNode* b = new ListNode(8, NULL);
    ListNode* c = new ListNode(7, NULL);
    ListNode* d = new ListNode(6, NULL);
    ListNode* e = new ListNode(9, NULL);

    l1->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    display(l1);
    cout<<middleNode(l1)->val<<endl;
    return 0;
}