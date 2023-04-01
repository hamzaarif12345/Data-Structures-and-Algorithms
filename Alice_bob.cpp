#include<bits/stdc++.h>
using namespace std;
// link : https://www.youtube.com/watch?v=5-lL9QuTpRA&list=PLQXZIFwMtjowKrFlzGcjMqchffJDRsz1E&index=9   
//timestamp: 1:20:00
//question link : https://www.codechef.com/problems/ALBOFACE?tab=statement
// use pointers in this question
// used two pointer approah as it is difficult to delete the elements of the array.
int game(int s,int e, vector<int> &piles){
    if(s>e) return 0; // base condition
    int op1=piles[s]-game(s+1,e,piles);
    int op2=piles[e]-game(s,e-1,piles);
    return max(op1,op2);
}
int main()
{
    vector<int> piles={9,1003,11,5};
    int n=piles.size();
    int ans=game(0,n,piles);
    if (ans>0) cout<<"Alice";
    else cout<<"Bob";
    return 0;
}

