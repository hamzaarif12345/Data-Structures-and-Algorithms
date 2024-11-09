//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string addStringsUsingCarry(string n1, string n2) {
    // Ensure n1 is the longer string for simplicity
    if (n1.length() < n2.length())
        swap(n1, n2);

    // Pad n2 with leading zeros to match the length of n1
    n2.insert(n2.begin(), n1.length() - n2.length(), '0');

    string result = "";     // Result string to store the sum
    int carry = 0;          // Initialize carry to 0

    // Add each digit from right to left
    for (int i = n1.length() - 1; i >= 0; --i) {
        int sum = (n1[i] - '0') + (n2[i] - '0') + carry;  // Sum of digits and carry
        carry = sum / 10;    // Calculate new carry
        result.push_back((sum % 10) + '0');  // Append the current digit to result
    }

    // If there's a carry left after the last addition
    if (carry > 0)
        result.push_back(carry + '0');
    
     while (result.back() == '0')   result.pop_back();
    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    return result;
}
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string n1="",n2="";
        for(int i=0;i<arr.size();i+=2) n1+=arr[i] + '0';
        for(int i=1;i<arr.size();i+=2) n2+=arr[i] + '0';
        return  addStringsUsingCarry(n1,n2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends