//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    vector<int> ans;
    int rows = mat.size();
    if (rows == 0) return ans; // Handle empty matrix
    int cols = mat[0].size();

    int l = 0, r = cols - 1, u = 0, d = rows - 1;

    while (l <= r && u <= d) {
        // Traverse from left to right along the top row
        for (int i = l; i <= r; i++) 
            ans.push_back(mat[u][i]);
        u++;

        // Traverse from top to bottom along the right column
        for (int i = u; i <= d; i++) 
            ans.push_back(mat[i][r]);
        r--;

        // Traverse from right to left along the bottom row (if still valid)
        if (u <= d) {
            for (int i = r; i >= l; i--) 
                ans.push_back(mat[d][i]);
            d--;
        }

        // Traverse from bottom to top along the left column (if still valid)
        if (l <= r) {
            for (int i = d; i >= u; i--) 
                ans.push_back(mat[i][l]);
            l++;
        }
    }

    return ans;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends