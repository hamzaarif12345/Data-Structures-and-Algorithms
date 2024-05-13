/*
861. Score After Flipping Matrix
Solved
Medium
Topics
Companies
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

 

Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
Example 2:

Input: grid = [[0]]
Output: 1
 
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        // Flip rows if needed to make leftmost bit 1
        for(int i = 0; i < grid.size(); ++i) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < grid[i].size(); ++j) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        // Flip columns if needed to maximize score
        for(int i = 0; i < grid[0].size(); ++i) {
            int zeros = 0, ones = 0;
            for(int j = 0; j < grid.size(); ++j) {
                if(grid[j][i] == 0) ++zeros;
                else ++ones;
            }
            if(zeros > ones) {
                for(int j = 0; j < grid.size(); ++j) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        
        // Calculate the score
        int score = 0;
        int n = grid[0].size() - 1;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                score += grid[i][j] * (1 << (n - j));
            }
        }
        
        return score;
    }
};
