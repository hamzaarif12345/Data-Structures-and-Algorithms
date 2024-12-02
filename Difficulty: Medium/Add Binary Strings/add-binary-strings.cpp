//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string s1, string s2) {
    string ans;
    int c = 0;
    if (s1.size() > s2.size()) swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    // Initialize result string
    ans = string(s2.size(), '0');

    int i;
    for (i = 0; i < s1.size(); i++) {
        int sum = (s1[i] - '0') + (s2[i] - '0') + c;
        ans[i] = (sum % 2) + '0';
        c = sum / 2;
    }
    for (; i < s2.size(); i++) {
        int sum = (s2[i] - '0') + c;
        ans[i] = (sum % 2) + '0';
        c = sum / 2;
    }
    if (c == 1) ans.push_back('1');
    while(ans.back()=='0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends