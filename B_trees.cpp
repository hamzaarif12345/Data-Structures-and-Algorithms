#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// link :https://www.youtube.com/watch?v=F1Fye5cXA0g&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=19
// traversal and finding height id of the tree 
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
int height(Node* root){
    if(root==NULL) return 0;
    int hl=height(root->left);
    int hr=height(root->right);
    return max(hl,hr);
    
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
    cout <<"\ninoder is : ";
    inorder(root);
    cout <<"\npreorder is : "; 
    preorder(root);
    cout <<"\npostorder is : "; 
    postorder(root);
    cout <<"\nfinding the height of the tree: ";
    int ans =height(n1);
    cout << ans+1;
    return 0;
}



