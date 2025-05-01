//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row;
        int val = 1;
        for (int k = 0; k < n; ++k) {
            row.push_back(val);
            val = val * (n - 1 - k) / (k + 1);
        }
        // row.push_back(1); // The last element is always 1
        return row;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends