/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }

    void inorder(Node* ptr){
        if(ptr == NULL)
            return;
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }

    void preorder(Node* ptr){
        if(ptr == NULL)
            return;
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void postorder(Node* ptr){
        if(ptr == NULL)
            return;
        preorder(ptr->left);
        preorder(ptr->right);
        cout << ptr->data << " ";
    }
};

int main(){
    Node* root = new Node(5);
    Node* temp = new Node(6);
    Node* temp2 = new Node(7);

    root->left = temp;
    root->right = temp2;

    root->inorder(root);
    return 0;
}