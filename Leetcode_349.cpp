/*
349. Intersection of Two Arrays
Solved
Easy
Topics
Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto a : nums1) m[a]=1;
        for(auto a : nums2){
            if(m[a]==1 || m[a]==2) m[a]=2;
            else m[a]=3;
        }
        vector<int> ans;
        for(auto a: m){
            if(a.second==2) ans.push_back(a.first);
        }
        return ans;
    }
};