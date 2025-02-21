//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for (char a : s) {
        if (a == '[' || a == '(' || a == '{') {
            st.push(a);
        } else {
            if (st.empty()) return false; // Ensure stack isn't empty before accessing top()
            
            if ((a == ')' && st.top() == '(') ||
                (a == ']' && st.top() == '[') ||
                (a == '}' && st.top() == '{')) {
                st.pop();
            } else {
                return false; // Mismatched brackets
            }
        }
    }return (st.empty());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends