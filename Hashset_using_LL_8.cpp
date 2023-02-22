#include<bits/stdc++.h>
using namespace std;

class MyHashset{
vector <list<int>> m;
int size;
public:
    MyHashset(){
        size=10;
        m.resize(size);
    }
    int hash(int key){
        return (key%size);
    }
    // see the implementation of the list in cpp
    list<int> :: iterator search(int key){
        int i=hash(key);
        return find(m[i].begin(),m[i].end(), key);
    }
    void addKey(int key){
        if(contains(key)) return;
        int i=hash(key);
        m[i].push_back(key);
    }
    void remove1(int key){
        if(!contains(key))
            return;
        int i=hash(key);
        m[i].erase(search(key));
    }
    bool contains(int key){
        int i=hash(key);
        if(search(key)==m[i].end())
            return true;
        else
            return false;
    }
};
int main(){
    MyHashset m;
    m.addKey(1);
    int i= m.contains(1);
    cout<<i;
    return 0;
}

