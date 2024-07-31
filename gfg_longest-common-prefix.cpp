//https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) return "";
        
        sort(arr.begin(), arr.end());
        int n = arr.size() - 1;
        for (int i = 0; i < arr[0].size(); i++) {
            if (arr[0][i] != arr[n][i]) {
                if (i == 0) return "-1";
                return arr[0].substr(0, i);
            }
        }
        return arr[0]; // All characters matched, return the first string
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends