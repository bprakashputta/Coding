#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


//Inorder, Preorder, Postorder are three variation of DFS(Depth First Search)
void inorder(Node* root){
    //left root right
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    //root left right
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    //left right root
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}




int main(){
    struct Node* root = new Node(10);
    root->left = new Node(4);
    root->right = new Node(14);
    cout<<root->data<<endl;
    root->left->left = new Node(3);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout<<endl<<"###############"<<endl;
    inorder(root);
    cout<<endl<<"###############"<<endl;
    preorder(root);
    cout<<endl<<"###############"<<endl;
    postorder(root);
    cout<<endl<<"###############"<<endl;
    // cout<<"###############"<<endl;
return 0;
}