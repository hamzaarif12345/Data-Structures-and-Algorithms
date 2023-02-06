#include<bits/stdc++.h>
using namespace std;
int main() {
    int prices[6]={7,1,5,3,6,4};
    int n=sizeof(prices)/sizeof(prices[0]);
    int m=0;
    for(int i=n-1;i>0;i--){
        for(int j=i-1;j>0;j--){
            int n1= prices[i]-prices[j];
            m=max(n1,m);
        }
    }
    cout<<m; 
    return 0;
}
