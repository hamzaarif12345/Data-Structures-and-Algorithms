/*
347. Top K Frequent Elements
Solved
Medium
Topics
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> a1;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int j = 1; // Initialize j to 1 as the first element is already considered
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                j++;
            } else {
                a1.push_back(make_pair(nums[i - 1], j));
                j = 1; // Reset j for the new element
            }
        }
        a1.push_back(make_pair(nums.back(), j));
        sort(a1.begin(), a1.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        for (int i = 0; i < k && i < a1.size(); i++) {
            ans.push_back(a1[i].first);
        }
        return ans;
    }
};
