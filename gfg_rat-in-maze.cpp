/*https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void backtrack(vector<vector<int>> &mat, int i, int j, string temp,vector<string> &ans){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0 || j<0 || i>=n ||j>=m || mat[i][j]==0) return;
        if(i==n-1 && j==m-1){
            ans.push_back(temp);
            return;
        }
        mat[i][j]=0;//this_is_imp
        backtrack(mat,i+1,j,temp+"D",ans);
        backtrack(mat,i,j+1,temp+"R",ans);
        backtrack(mat,i-1,j,temp+"U",ans);
        backtrack(mat,i,j-1,temp+"L",ans);
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        string temp;
        backtrack(mat,0,0,temp,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends