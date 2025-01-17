//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        vector<int> ans;
        int c=0;
        int prod=1;
        int i=0;
        int index=-1;
        for(auto a: arr) {
            if(a==0) {c++; index=i;}
            if(a!=0) prod*=a;
            i++;
        }
        for(int i=0;i<arr.size();i++) ans.push_back(0);
        if(c>=2) return ans;
        if(c==1) {
            ans [index]=prod;
            return ans;
        }
        for(int i=0;i<arr.size();i++){
            ans[i]=int(prod/arr[i]);
        }return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends