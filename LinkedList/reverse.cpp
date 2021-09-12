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

ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return NULL;
        else if(head->next == NULL) return head;
        else{
            ListNode* prev = NULL;
            ListNode* next = NULL;

            while(head!=NULL){
                next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }

            return prev;
        }
        
        
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
    display(reverseList(l1));
    
    return 0;
}