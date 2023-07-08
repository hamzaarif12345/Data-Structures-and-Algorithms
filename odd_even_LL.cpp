/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

328
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
        int data;
        node *next;
    };
struct node *start =NULL,*temp,*nn, *current, *temp2, *fast, *slow;
int a;
void create(){
    do{
        cout<<"\nenter the data ";
        int b;
        cin>>b;
        nn=(struct node*)malloc(sizeof(struct node*));
        nn->data=b;
        nn->next=NULL;
        /*nn->prev=NULL;*/
        if(start==NULL){
            start=nn;
            current =nn;
        }
        else {
            current->next=nn;
            //nn->prev=current;
            current=nn;
        }
        cout<<"press -1 to stop ";
        cin>>a;
        /*if(a==-1){
            current->next=start;}*/
    }while(a!=-1);
}
void display(){
    temp=start;
    while(temp!=NULL){
        cout<<temp->data<<"->"<<" ";
        temp=temp->next;
    }
    //cout<<"->"<<start->data;
}
int x=0;
void middle_element(){
    
    temp=start;
    while(temp!=NULL){
        //cout<<temp->data<<"->"<<" ";
        temp=temp->next;
        x++;
    }
    //cout<<"\n"<<x;
    
    if(x%2!=0){
        temp=start;
        for(int i=0;i<(x/2);i++){
            temp=temp->next;}
        cout<<"\nMiddle: "<<temp->data;
    }
    else{
        temp=start;
        for(int i=0;i<(x/2);i++){
            temp=temp->next;}
        cout<<"\nmiddle is: "<<temp->data;
        temp=temp->next;
        cout<<" "<<temp->data;
    }
    //cout<<"\n"<<x;
}
void optimized(){
    fast=slow=start;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"\n"<<slow->data;
}

void odd_even(){
    temp =start;
    struct node *odd=start;
    struct node *even=start->next, *even_start=start->next;
    while(odd->next && even->next){
        odd->next=even->next;
        even->next=odd->next->next;
        odd=odd->next;
        even=even->next;

    }
    odd->next=even_start;
}
int main(){
    create();
    //display();
    //middle_element();// not optimized
    //optimized();
    display();
    odd_even();
    display();  
    return 0;
}