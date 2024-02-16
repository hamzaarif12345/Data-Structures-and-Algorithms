/*
1481. Least Number of Unique Integers after K Removals
Solved
Medium
Topics
Companies
Hint
Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

Example 1:

Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.
Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 

Constraints:
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (auto a : arr) m[a]++;
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if (m[a] != m[b]) {
                return m[a] > m[b]; // Sort by frequency in decreasing order
            } else {
                return a < b; // If frequencies are equal, sort by value in increasing order
            }
        });
        for(int i=0;i<k;i++){
            arr.pop_back();
        }
        set<int> s;
        for(auto a: arr){ s.insert(a);}
        return s.size();
    }
};
