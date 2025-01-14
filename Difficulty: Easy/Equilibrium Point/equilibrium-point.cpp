//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        vector<int> v,v2;
        int ans=0;
        for(int i=0;i<arr.size();i++) {
            ans+=arr[i];
            v.push_back(ans);
        }
        ans=0;
        for(int i=arr.size()-1;i>=0;i--) {
            ans+=arr[i];
            v2.push_back(ans);
        }
        reverse(v2.begin(),v2.end());
        for(int i=0;i<v.size();i++) {
            if(v[i]==v2[i]) return i;
        }return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends