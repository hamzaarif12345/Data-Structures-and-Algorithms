#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start =NULL,*temp,*nn, *current=NULL, *temp2, *last;
int a;
void create(){
    do{
        cout<<"\nenter the data ";
        int b;
        cin>>b;
        nn=(struct node*)malloc(sizeof(struct node*));
        nn->data=b;
        nn->next=NULL;
        nn->prev=NULL;
        if(start==NULL){
            start=nn;
            current =nn;
        }
        else {
            current->next=nn;
            nn->prev=current;
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
    //cout<<temp->data;
    //cout<<"-> "<<start->data;
}
//my revesal fiucntion
/*
int x=0;
void reversal(){
    temp=start;
    while(temp!=NULL){
        temp=temp->next;
        x++;}
    last=temp;
    start=temp;
    start->next=temp->prev;
    start->prev=NULL;
    temp=temp->prev;

    int y=x-1;
    cout<<y;
    while(y>0){

        temp->next=temp->prev;
        temp->prev=temp->next;
        temp=temp->prev;
        y--;
    }*/
    
    /*temp2=temp->prev;
    start=temp;
    start->next=temp2;
    temp=start;
    temp->next=start->next;
    for(int i=0;i<x-1;i++){

    }}*/

void reverse()
    {
        // Initialize current, previous and next pointers
        node* current = start;
        node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        start = prev;
    }

void toDecimal(){
    reverse();
    temp=start;
    int sum=0;
    for(int i=2;i>0;i--){
        sum += temp->data*(pow(2,i-1));
    }
    cout<<"\n"<<sum;
}
void optimized(){
    temp=start;
    int sum=0;
    while(temp!=NULL){
        sum*=2;
        sum+=(temp->data);
        temp=temp->next;
    }
    cout<<"Number is : "<<sum;
}

int main(){
    create();
    cout<<"\ndisplay: ";
    display();
    //cout<<"\nAfter reversal: ";
    //reversal();
    //reverse();
    //display();
    //toDecimal();
    optimized();

    return 0;
}

// link : https://leadcoding.in/convert-binary-number/