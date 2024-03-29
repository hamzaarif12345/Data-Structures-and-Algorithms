/*
2962. Count Subarrays Where Max Element Appears at Least K Times
Solved
Medium
Topics
Companies
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int maxCount = 0; // Initialize the count of maximum value in the window
        int maxValue = *max_element(nums.begin(), nums.end()); // Find the maximum value in nums
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] == maxValue) ++maxCount; // Increment maxCount if current element is the maximum value
            while (maxCount >= k) { // If maxCount exceeds or equals k, slide the window from the left
                ans += n - j; // Add the number of subarrays ending at the current position to the answer
                if (nums[i] == maxValue) --maxCount; // Decrement maxCount if the element going out of window is the maximum value
                ++i; // Slide the window from the left
            }
            ++j; // Move the window to the right
        }
        return ans;
    }
};
