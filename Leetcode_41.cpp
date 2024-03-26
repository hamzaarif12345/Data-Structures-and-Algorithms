/*
41. First Missing Positive
Hard
Topics
Companies
Hint
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

*/
// NOt by self


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};



/*
Handling non-positive integers:

In the first loop, the code iterates through the given array nums.
For each element nums[i] that is less than or equal to 0, it modifies nums[i] to be n + 1, where n is the size of the array.
This effectively ignores non-positive integers because they cannot contribute to the sequence of positive integers.
Marking existing positive integers:

In the second loop, it iterates through the modified nums array.
For each positive integer nums[i], it checks if its absolute value is less than or equal
 to n (to ensure it's within the valid range of array indices) and if nums[abs(nums[i]) - 1] is positive.
If both conditions are true, it multiplies nums[abs(nums[i]) - 1] by -1. This step marks the 
presence of positive integers by making the corresponding indices negative.
Finding the first missing positive:

Finally, the code iterates through the modified nums array again.
It looks for the first positive integer nums[i]. If it finds one, it returns i + 1, indicating 
that i + 1 is the first missing positive integer.
If no positive integer is found during the iteration, it returns n + 1, 
suggesting that all positive integers from 1 to n are present in the array, so the first missing positive integer is n + 1.
Let's illustrate this with an example using the array nums = [3, 4, -1, 1]:

First loop: Modify nums to [3, 4, 5, 1].
Second loop: Mark nums as [-3, -4, 5, -1].
Third loop: Find the first positive integer at index 2, indicating that 2 is the first missing positive integer.
This algorithm ensures that the first missing positive integer is found efficiently, without using extra space, 
and has a time complexity of O(n), where n is the size of the input array nums.
*/
