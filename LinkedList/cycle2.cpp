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

//Brute Time: O(n) Space: O(n)
ListNode* detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL) 
        return NULL;
    set<ListNode*> s;
    ListNode* temp = head;
    while(temp->next != NULL && s.find(temp->next) == s.end()){
        cout << "value=" << temp->val << endl;
        s.insert(temp);
        temp = temp->next;
    }
    return temp->next;
}

//Optimal
ListNode* detectCycleOptimal(ListNode* head){
    if(head == NULL || head->next == NULL) 
            return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *entry = head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){ 
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }

    return NULL;
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
    d->next = b;

    
    //display(l1);

    cout << "Brute\n" << detectCycle(l1)->val << endl;
    cout << "Optimal\n" << detectCycleOptimal(l1)->val << endl;
    
    return 0;
}