#include <iostream>
#include<bits/stdc++.h>
//link https://www.youtube.com/watch?v=JHldgHi6DPM
using namespace std;

int fibo(int n, vector<int> dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    int ans=fibo(n-1,dp)+fibo(n-2,dp);
    dp[n]=ans;
    return ans;
}
int main(){
    vector<int> dp(100,-1);
    cout<<fibo(10,dp);
    return 0;
}
