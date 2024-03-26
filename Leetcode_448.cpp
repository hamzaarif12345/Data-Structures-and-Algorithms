/*

448. Find All Numbers Disappeared in an Array
Solved
Easy
Topics
Companies
Hint
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=1;i<n+1;i++){
            m[i]=0;
        }
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        vector<int> ans;
        for(auto a : m) {
            if(a.second ==0) ans.push_back(a.first);
        }return ans;
    }
};