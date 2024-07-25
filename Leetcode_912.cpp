/*
912. Sort an Array
Solved
Medium
Topics
Companies
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
*/

class Solution {
public:
    void merge(vector<int>& a, int s, int mid, int e) {
        vector<int> t1(a.begin() + s, a.begin() + mid + 1);
        vector<int> t2(a.begin() + mid + 1, a.begin() + e + 1);
        
        int i = 0, j = 0, k = s;
        while (i < t1.size() && j < t2.size()) {
            if (t1[i] <= t2[j]) {
                a[k++] = t1[i++];
            } else {
                a[k++] = t2[j++];
            }
        }
        
        while (i < t1.size()) {
            a[k++] = t1[i++];
        }
        
        while (j < t2.size()) {
            a[k++] = t2[j++];
        }
    }
    
    void merge_sort(vector<int>& a, int s, int e) {
        if (s < e) {
            int mid = s + (e - s) / 2;
            merge_sort(a, s, mid);
            merge_sort(a, mid + 1, e);
            merge(a, s, mid, e);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};