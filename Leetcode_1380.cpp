/*
1380. Lucky Numbers in a Matrix
Solved
Easy
Topics
Companies
Hint
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

*/
//original

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        unordered_map<int,pair<bool,bool>> m;
        for(int i=0;i<matrix.size();i++){
            int mn=INT_MAX;
            for(int j=0;j<matrix[0].size();j++)    mn=min(mn,matrix[i][j]);
            m[mn].first=true;
        }
        for(int i=0;i<matrix[0].size();i++){
            int mn=INT_MIN;
            for(int j=0;j<matrix.size();j++)    mn=max(mn,matrix[j][i]);
            m[mn].second=true;
        }
        for(auto a:m){
            if(a.second.first && a.second.second)  ans.push_back(a.first);
        }
        return ans;

    } 
};


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxMin = INT_MIN;
        for (int i = 0; i < m; i++) {
            int min = INT_MAX;
            for (int j = 0; j < n; j++)
                min = std::min(min, matrix[i][j]);
            maxMin = std::max(maxMin, min);
        }

        int minMax = INT_MAX;
        for (int j = 0; j < n; j++) {
            int max = INT_MIN;
            for (int i = 0; i < m; i++)
                max = std::max(max, matrix[i][j]);
            minMax = std::min(minMax, max);
        }
        
        if (maxMin != minMax) return vector<int> { };
        return vector<int> { maxMin };
    }
};