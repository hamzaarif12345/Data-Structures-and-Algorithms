#include<bits/stdc++.h>
using namespace std;
//link https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
class graph{
    int v;
    vector<list<int>> adj; 
    public:
        graph(int v);
        void addedge(int v,int w);
        void BFS(int s);
};

graph ::graph(int v){
    this->v=v;
    adj.resize(v);
}
void graph::addedge(int v,int w){
    adj[v].push_back(w);
}
void graph::BFS(int s){
    vector<bool> visited;
    visited.resize(v,false);
    list<int> queue;
    visited[s]=true;
    queue.push_back(s);
    while(!queue.empty()){
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(auto ajdacent :adj[s]){
        if(!visited[ajdacent]){
            visited[ajdacent]=true;
            queue.push_back(ajdacent);
        }
    }

    }
    


}
int main(){
    graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    cout<< "Following is Breadth First Traversal "<< "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
