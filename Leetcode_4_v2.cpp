/*
4. Median of Two Sorted Arrays
Solved
Hard
Topics
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0, j = 0;
        int a = nums1.size();
        int b = nums2.size();

        if ((a + b) % 2 != 0) {
            while (i + j < (a + b + 1) / 2) {
                if (i < a && (j == b || nums1[i] <= nums2[j])) {
                    i++;
                } else {
                    j++;
                }
            }
            return max(i > 0 ? nums1[i - 1] : INT_MIN, j > 0 ? nums2[j - 1] : INT_MIN);
        } else {
            int first = 0, second = 0;
            while (i + j <= (a + b) / 2) {
                first = second;
                if (i < a && (j == b || nums1[i] <= nums2[j])) {
                    second = nums1[i++];
                } else {
                    second = nums2[j++];
                }
            }
            return (first + second) / 2.0;
        }
    }
};
