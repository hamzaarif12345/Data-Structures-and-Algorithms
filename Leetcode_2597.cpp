/*
2597. The Number of Beautiful Subsets
Solved
Medium
Topics
Companies
Hint
You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

 

Example 1:

Input: nums = [2,4,6], k = 2
Output: 4
Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
Example 2:

Input: nums = [1], k = 1
Output: 1
Explanation: The beautiful subset of the array nums is [1].
It can be proved that there is only 1 beautiful subset in the array [1].
 

Constraints:

1 <= nums.length <= 20
1 <= nums[i], k <= 1000
*/
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> s;
        vector<int> su;
        helper(su, s, 0, nums, k);
        return s.size()-1;
    }

    void helper(vector<int>& su, vector<vector<int>>& s, int i, vector<int>& nums, int k) {
        if (diff(su, k)) {
            s.push_back(su);
        }
        for (int j = i; j < nums.size(); j++) {
            su.push_back(nums[j]);
            helper(su, s, j + 1, nums, k);
            su.pop_back();
        }
    }

    bool diff(vector<int>& v, int k) {
        if (v.size() <= 1) return true;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (abs(v[j] - v[i]) == k) return false;
            }
        }
        return true;
    }
};
