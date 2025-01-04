//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
    unordered_map<int, vector<int>> m; // To store all indices of each element
    int ans = 0;

    // Populate the map with all occurrences of each element
    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]].push_back(i);
    }

    // Iterate through all pairs of elements
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int complement = target - (arr[i] + arr[j]);

            // Check if the complement exists in the map
            if (m.find(complement) != m.end()) {
                for (int k : m[complement]) {
                    if (k > j) { // Ensure valid triplet indices
                        ans++;
                    }
                }
            }
        }
    }

    return ans;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends