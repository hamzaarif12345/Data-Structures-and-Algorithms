//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    unordered_map<int, string> m;

    string calculate(int n) {
        if (m.count(n)) return m[n];  // return memoized result if exists

        string prev = calculate(n - 1);
        string ans = "";

        int count = 1;
        for (int i = 1; i < prev.size(); i++) {
            if (prev[i] == prev[i - 1]) {
                count++;
            } else {
                ans += to_string(count) + prev[i - 1];
                count = 1;
            }
        }

        // append the last sequence
        ans += to_string(count) + prev.back();

        m[n] = ans; // memoize the result
        return ans;
    }

    string countAndSay(int n) {
        // base case
        m[1] = "1";

        return calculate(n);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends