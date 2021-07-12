//Reverse a linked list in group of k
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

//OPTIMAL -> Time: O(n) Space: O(1)
ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* result = new ListNode(0, head);
    ListNode* prev = result;
    ListNode* cur = head;

    int size=0;
    while(cur!=NULL){
        size++;
        cur = cur->next;
    }

    cout<<"size: "<<size<<endl;

    cur = head->next;

    while(size>=k){
        //to reverse k nodes -> k-1 pointers need to be changed
        for(int i=0; i<k-1; i++){ 
            head->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = head->next;
        }
        //display(result->next);
        size -= k;
        if(cur!=NULL){
            prev = head;
            head = prev->next;
            cur = head->next;
        }
        
    }

    return result->next;

}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(int);

    ListNode* l1 = new ListNode(a[0],NULL);
    ListNode* temp = l1;
    for(int i=1; i<n; i++){
        ListNode* newNode = new ListNode(a[i],NULL);
        temp->next = newNode;
        temp = temp->next;
    }
    
    display(l1);
    display(reverseKGroup(l1, 3));

    return 0;
}