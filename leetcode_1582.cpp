/*
1582. Special Positions in a Binary Matrix
Solved
Easy
Topics
Companies
Hint
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    int rowSum = 0;
                    int colSum = 0;

                    for (int k = 0; k < rows; k++) {
                        rowSum += mat[k][j];
                    }

                    for (int k = 0; k < cols; k++) {
                        colSum += mat[i][k];
                    }

                    if (rowSum == 1 && colSum == 1) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};