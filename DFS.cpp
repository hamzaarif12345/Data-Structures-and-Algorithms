#include<bits/stdc++.h>
using namespace std;
//link  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
class graph{
    void DFSutil(int v);
    public:
        map<int, bool> visited;
        map<int ,list<int> > adj;
        void addedge(int v,int w);
        void DFS();

};

void graph::addedge(int v,int w){
    adj[v].push_back(w);
}
void graph::DFSutil(int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int> ::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            DFSutil(*i);
        }
    }

}
void graph::DFS(){
    for(auto i:adj){
        if(visited[i.first]==false){
            DFSutil(i.first);
        }
    }
}
int main(){
    graph g;
    g.addedge(0,1);
    g.addedge(0,9);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(9,3);
    cout<<"graph traversal is :";
    g.DFS();
    return 0;

}