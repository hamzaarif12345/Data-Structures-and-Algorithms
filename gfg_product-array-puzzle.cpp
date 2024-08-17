//https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n=nums.size();
        vector<long long int> res(n, 0);
        long long int cnt0 = 0, prod = 1;

        // Calculate product of all elements and count zeros
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt0++;
            } else {
                prod *= nums[i];
            }
        }

        // Generate the result based on the number of zeros
        for (int i = 0; i < n; i++) {
            if (cnt0 == 0) {
                res[i] = prod / nums[i];
            } else if (cnt0 == 1 && nums[i] == 0) {
                res[i] = prod;
            } else {
                res[i] = 0;
            }
        }

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends