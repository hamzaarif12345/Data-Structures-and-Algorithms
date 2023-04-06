#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// link :https://www.youtube.com/watch?v=iw44T1jDDQE&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=20
// printing hte elaf node of the tree
// pls chk if working properly
struct Node{
    int val;
    Node *left, *right;
};
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void print_leaf(Node* root){
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL) cout << root->val;
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node* root =new Node;
    root->val=90;
    Node* n1=new Node;
    n1->val=5;
    Node* n2= new Node;
    n2->val=10;
    root->left=n1;
    root->right=n2;
    Node* n3=new Node;
    n3->val=14;
    Node* n4=new Node;
    n4->val=16;
    n1->left=n3;
    n1->right=n4;
    
    cout <<"\nprinting leaf nodes : "; 
    print_leaf(root);
    //preorder(root);
    return 0;
}



