//check if a linked list is palindrome or not
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

//OPTIMAL -> Time: O(n/2 + n/2 + n/2) = O(3n/2) Space: O(1)
bool isPalindrome(ListNode* head) {
    if(head->next == NULL) return true;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    //middle of linked list
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //reversing the later part
    ListNode* temp = slow->next;
    ListNode* cur = temp->next;
    while(cur!=NULL){
        temp->next = cur->next;
        cur->next = slow->next;
        slow->next = cur;
        cur = temp->next;
    }

    slow = slow->next;

    //checking for values
    while(slow!=NULL){
        if (head->val != slow->val) return false;
        head = head->next;
        slow = slow->next;
    }

    return true;
}

int main(){
    int a[] = {1,3,4,4,3,1};
    int n = sizeof(a)/sizeof(int);

    ListNode* l1 = new ListNode(a[0],NULL);
    ListNode* temp = l1;
    for(int i=1; i<n; i++){
        ListNode* newNode = new ListNode(a[i],NULL);
        temp->next = newNode;
        temp = temp->next;
    }
    
    display(l1);
    cout<<isPalindrome(l1)<<endl;

    return 0;
}