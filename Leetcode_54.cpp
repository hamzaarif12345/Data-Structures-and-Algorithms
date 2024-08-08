/*
Code


Testcase
Testcase
Test Result
54. Spiral Matrix
Solved
Medium
Topics
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

 class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> ans;
        int l = 0, r = matrix[0].size() - 1;
        int u = 0, d = matrix.size() - 1;
        while(l <= r && u <= d){
            for(int i = l; i <= r; i++) ans.push_back(matrix[u][i]);
            u++;
            if(u > d) break;
            
            for(int i = u; i <= d; i++) ans.push_back(matrix[i][r]);
            r--;
            if(r < l) break;
            
            for(int i = r; i >= l; i--) ans.push_back(matrix[d][i]);
            d--;
            if(d < u) break;
            
            for(int i = d; i >= u; i--) ans.push_back(matrix[i][l]);
            l++;
        }
        return ans;
    }
};
