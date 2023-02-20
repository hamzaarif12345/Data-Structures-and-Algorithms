#include<bits/stdc++.h>
using namespace std;

class MyHashset{
vector <list<pair<int, int>>> m;
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
    list<pair<int, int>> :: iterator search(int key){
        int i=hash(key);
        list<pair<int, int>> :: iterator it=m[i].begin();
        while(it!=m[i].end()){
            if(it->first==key) return it;
            it++;
        }
        return it;
    }
    void put(int key, int value){
        int i=hash(key);
        remove1(key);
        m[i].push_back({key,value});
    }
    void remove1(int key){
        int i=hash(key);
        list<pair<int , int>> :: iterator it = search(key) ;
        if(it!=m[i].end()){
            m[i].erase(it);
        }
    }
    int get(int key){
        int i=hash(key);
        list<pair<int , int>> :: iterator it = search(key) ;
        if(it==m[i].end()){
            return -1;
        }
        else
            return (it->second);
    }
};
int main(){
    MyHashset m;
    
    return 0;
}

