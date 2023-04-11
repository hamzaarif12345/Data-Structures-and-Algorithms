#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// link :https://www.youtube.com/watch?v=2MFSFiwh4qQ&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=23
// grapht traversal
// using adjacency list
// done till 1:15
int m[10][10];
void clear_graph(){
    memset(m,0,sizeof m);
}
void add_edge(int s, int d){
    m[s][d]=1;
    m[d][s]=1;
}
void del_edge(int s, int d){
    m[s][d]=0;
    m[d][s]=0;
}
void print(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void DFS(int i,vector<int> &cont){ // cont to chk if the node is already visited or not
    if(cont[i]==1) return;
    cont[i]=1; // if it is not visited then the above line wont be executed
    cout << i << "  ";
    for(int j=0;j<10;j++) 
        if (m[i][j]==1) 
            DFS(j,cont);
    
    
}
int main(){
    vector<int> cont(10,0);
    clear_graph();
    add_edge(3,2);
    add_edge(4,5);
    print();
    for(int i=0;i<20;i++){ // the rason for dsoing this is that if we dont have the neighbour then it wont move forward so we will chk all:)
        //cout
        DFS(i,cont);
        cout<<endl;
    }
    return 0;
}
