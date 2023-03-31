#include<bits/stdc++.h>
//link :https://www.youtube.com/watch?v=w1t_ZDwLPwg
using namespace std;
bool comp(vector<int>&a,vector<int> &b){
    return a<b;
}

int main(){
    vector<vector<int>> ac={{1,2},{5,6},{3,8}};
    /*for(int i=0;i<ac.size();i++)
        cout<<ac[i][0]<<" "<<ac[i][1]<<endl;*/
    sort(ac.begin(),ac.end(),comp);
    /*for(int i=0;i<ac.size();i++)
        cout<<ac[i][0]<<" "<<ac[i][1]<<endl;*/
        
    int fr=0;
    int ans =0;
    for(int i=0;i<ac.size();i++){
        if(fr<ac[i][0]){
            fr=ac[i][1];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}


