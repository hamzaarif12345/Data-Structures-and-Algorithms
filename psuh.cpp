#include<bits/stdc++.h>
using namespace std;
class com{
public:
    void sol(int i, int k,int target,int sum, vector<int> &arr,vector<vector<int>> &ans){
        
        if(k==0){
            if(sum==target) {
                ans.push_back(arr);}
            return;
        }
        if(sum>target){
            return;
        }
        if(i==10) return;
        sum+=i;
        arr.push_back(i);
        sol(i+1,k-1,target,sum,arr,ans);
        sum-=i;
        arr.pop_back();
        sol(i+1,k,target,sum,arr,ans);
        
        
    }
    
};
int main(){
    com c;
    vector <int> a;
    vector<vector<int>> b;
    c.sol(0,3,6,0,a,b);
    return 0;
}
