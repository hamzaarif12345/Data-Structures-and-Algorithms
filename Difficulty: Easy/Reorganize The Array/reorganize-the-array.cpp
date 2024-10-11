//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
    unordered_map<int, bool> m;
    for (auto a : arr) {
        m[a] = true;  // Store each element's presence
    }
    
    vector<int> ans(arr.size(), -1);  // Initialize result with -1, size equal to arr
    
    for (int i = 0; i < arr.size(); i++) {
        if (m.find(i) != m.end()) {
            ans[i] = i;  // If the element i+1 exists in the input array, assign it
        }
    }
    
    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends