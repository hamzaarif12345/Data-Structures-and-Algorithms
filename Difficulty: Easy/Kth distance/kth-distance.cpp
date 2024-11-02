//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
    unordered_map<int, int> m;

    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;  // Add current element to the map
        if (m[arr[i]] > 1) {
            return true;  // Duplicate found within range k
        }

        // Remove elements that are out of the k range
        if (i >= k) {
            m[arr[i - k]]--;  // Decrement count of element that goes out of range
            if (m[arr[i - k]] == 0) {
                m.erase(arr[i - k]);  // Remove from map if count is zero
            }
        }
    }

    return false;  // No duplicates within range k
}
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends