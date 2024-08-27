/*
https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        stack<int> s;
        vector<int> a1, a2;
        
        // Finding nearest smaller elements on the left
        for(auto a : arr) {
            while(!s.empty() && s.top() >= a) {
                s.pop();
            }
            if(s.empty()) {
                a1.push_back(0);
            } else {
                a1.push_back(s.top());
            }
            s.push(a);
        }
        
        // Clear the stack
        while(!s.empty()) s.pop();
        
        // Finding nearest smaller elements on the right
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if(s.empty()) {
                a2.push_back(0);
            } else {
                a2.push_back(s.top());
            }
            s.push(arr[i]);
        }
        
        reverse(a2.begin(), a2.end());
        
        // Finding maximum difference
        int ans = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            ans = max(abs(a2[i] - a1[i]), ans);
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
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends