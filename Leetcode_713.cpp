/*
713. Subarray Product Less Than K
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        // int a=0,b=0;
        int p=1;
        for(int i=0;i<nums.size();i++){
            p=1;
            for(int j=i;j<nums.size();j++){
                
                p*=nums[j];
                if(p < k) ans++ ;
                else {break;}
            }
        }
        return ans;
    }
};


//optimize 


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int p = 1;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            p *= nums[i];
            while (left <= i && p >= k) {
                p /= nums[left++];
            }
            ans += (i - left + 1);
        }
        return ans;
    }
};
