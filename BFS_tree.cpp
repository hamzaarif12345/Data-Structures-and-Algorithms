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
void BFS(Node* root){
    queue<Node*> q; // code snippet for trees
    if(root) q.push(root);
    while(q.size()){
        auto a=q.front(); // queue have front rather then top
        q.pop();
        cout << a->val <<" ";
        if(a->left) q.push(a->left);
        if(a->right) q.push(a->right);
        
    }
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
    cout <<"\nPrinting BFS of the trees : "; 
    BFS(root);
    return 0;
}




