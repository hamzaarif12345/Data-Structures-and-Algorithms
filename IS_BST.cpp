#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// link :https://www.youtube.com/watch?v=l_g3aH8WAVI&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=22   timestamp 36
// checking whether the tree is BST or not 
// space complexity is  O(h)  where height is h
// operation of BST : searching, insertion,         
struct Node{
    int val;
    Node *left, *right;
};

bool is_BST(int l, int r,Node* root){
    if(root==NULL) return true;
    if(root->val>r || root->val<l) return false;
    if(is_BST(l,root->val,root->left) && is_BST(root->val+1,r,root->right)) return true;
    return false;
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
    int k=is_BST(INT_MIN,INT_MAX,root);
    cout<<k;
    return 0;
}






