#include<bits/stdc++.h>
using namespace std;
vector<int> arr={2,2,2};
vector<vector<int>> ans;
void helper(int pos, int n, vector<int> &nums){
    if(pos>=n){
        ans.push_back(nums);
        return;
    }
    unordered_set<int> set;
    for(int i=pos;i<n;i++){
        if(set.find(nums[i])!=set.end())
            continue;
        set.insert(nums[i]);
        swap(nums[i],nums[pos]);
        helper(pos+1,n,nums);
        swap(nums[i],nums[pos]);//backtracking step important to get the original array
    }
}
int main(){
    helper(0,arr.size(),arr);
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}