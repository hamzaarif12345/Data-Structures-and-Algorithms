#include <bits/stdc++.h>
using namespace std;

struct Node{
        int data;
        struct Node *left,*right;
    };
Node* newnode(int data){
        Node* temp=new Node;
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        return temp;

    }
void inorder(struct Node* node){
        if(node==NULL)
            return ;
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);}
void preorder(struct Node* node){
    if(node==NULL)
        return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
    
 }
void postorder(Node* node){
    if(node==NULL)
       return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main(){
        struct Node* root=newnode(1);
        root->left=newnode(2);
        root->right=newnode(3);
        root->left->left=newnode(4);
        root->left->right=newnode(5);
        cout<<"inoreder traversal ";
        inorder(root);
        cout<<"\npreoder ";
        preorder(root);
        cout<<"\npostorder"<<" ";
        postorder(root);
        return 0;
    }
    
