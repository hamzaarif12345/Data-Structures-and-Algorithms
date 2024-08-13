/*
https://www.geeksforgeeks.org/problems/square-root/1
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if(n==1) return 1;
        if(n==2) return 1;
        int ans=1;
        for(int i=2;i<=n/2;i++){
            
            if(i*i==n) return i;
            if(i*i>n) return ans;
            ans=i;
        }return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends