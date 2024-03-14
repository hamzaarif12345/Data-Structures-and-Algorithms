/*
930. Binary Subarrays With Sum
Solved
Medium
Topics
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 */
 class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int left1 = 0, left0 = 0, right = 0;
        int sum1 = 0, sum0 = 0;
        int count = 0;

        while (right < n) {
            sum1 += nums[right];
            sum0 += nums[right];
            
            while (left1 <= right && sum1 > goal) {
                sum1 -= nums[left1];
                left1++;
            }
            
            while (left0 <= right && sum0 >= goal) {
                sum0 -= nums[left0];
                left0++;
            }
            
            count += left0 - left1;
            
            right++;
        }

        return count;
    }
};
