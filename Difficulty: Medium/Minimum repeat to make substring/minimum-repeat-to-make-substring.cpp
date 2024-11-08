//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minRepeats(std::string s1, std::string s2) {
        // Check if every character in s2 exists at least once in s1
        for (char c : s2) {
            if (s1.find(c) == std::string::npos) return -1;
        }

        // Now, try to find the minimum number of repeats required
        std::string temp = s1;
        int repeats = 1;
        
        // Repeat s1 until s2 is a substring of the repeated string
        while (temp.find(s2) == std::string::npos) {
            temp += s1;
            repeats++;

            // Optimization: If temp length becomes too large compared to s2, return -1
            if (temp.length() > s2.length() * 2 + s1.length()) {
                return -1;
            }
        }
        
        return repeats;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends