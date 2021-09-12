#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int key){
        data = key;
        left = NULL;
        right = NULL;
    }  
};

node* buildTree(){
    //preorder build
    int key;
    cout << "data:";
    cin >> key;

    if(key == -1) 
        return NULL;

    node* ptr = new node(key);
    ptr->left = buildTree();
    ptr->right = buildTree();

    return ptr;
}

node* levelOrder(node* ptr){
    //there is no node
    if(ptr == NULL)
        return NULL;
    
    //1. leaf node -> left=right=null
    if(ptr->left == NULL && ptr->right == NULL)
        cout << ptr->data << " ";
    //2. only left=null
    else if(ptr->left == NULL && ptr->right != NULL)
        cout << ptr->data << " " << ptr->right->data << " ";
    //3. only right=null
    else if(ptr->left != NULL && ptr->right == NULL)
        cout << ptr->data << " " << ptr->left->data << " ";
    //4. both children are present
    else
        cout << ptr->data << " " << ptr->left->data << " " << ptr->right->data << " ";
    levelOrder(ptr->left);
    levelOrder(ptr->right);

    return ptr;
}

int main(){
    node* root = buildTree();
    // cout << root << endl;
    cout << "success !" << endl;
    levelOrder(root);
    cout << "levelorder done" << endl;
}