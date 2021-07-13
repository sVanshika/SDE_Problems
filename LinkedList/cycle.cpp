#include <iostream>
#include <set>
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

//BRUTE -> Time: O(n) Space: O(n) (set)
bool hasCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return false;
    else{
        set<ListNode*> s;
        while(true){
            if(head==NULL) break;
            //node not found in set
            if(s.find(head) == s.end()){ 
                //cout<<"inserting "<<head->val<<endl;
                s.insert(head);
                head=head->next;
            }
            else return true;
        }
        return false;
    }
}

//OPTIMAL -> Time: O(n) Space:O(1)
bool hasCycleOptimal(ListNode* head){
    if(head==NULL || head->next==NULL) return false;
    else {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
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
    //d->next = b;

    
    display(l1);
    cout<<hasCycle(l1)<<endl;
    cout<<hasCycleOptimal(l1)<<endl;
    return 0;
}