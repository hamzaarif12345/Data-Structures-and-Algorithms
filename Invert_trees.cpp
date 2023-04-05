#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// link :https://www.youtube.com/watch?v=F1Fye5cXA0g&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=19
// invert of the tree or the mirror of the image
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

void invert_tree(Node* root){
    if(root==NULL) return ;
    invert_tree(root->left);
    invert_tree(root->right);
    swap(root->left,root->right);
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
    cout <<"\npreorder is : "; 
    preorder(root);
    invert_tree(root);
    cout <<"\npreorder after swapping is : "; 
    preorder(root);
    
    
    return 0;
}



