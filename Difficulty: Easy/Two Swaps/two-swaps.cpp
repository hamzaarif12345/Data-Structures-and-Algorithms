//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        bool f=false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1) f=true;
        }
        if(!f) return true;
        int k = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (arr[i] != i + 1) {  // Keep swapping until the correct element is in position
                swap(arr[i], arr[arr[i] - 1]);
                k++;  // Count the number of swaps
                if (k > 2) return false;  // More than two swaps are not allowed
            }
        }
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=i+1) return false;
        }
        return k == 2;
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
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends