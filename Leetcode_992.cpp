/*
992. Subarrays with K Different Integers
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4
*/


#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostKDistinct(A, K) - atMostKDistinct(A, K - 1);
    }
    
private:
    int atMostKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> count;
        int i = 0, res = 0;
        for (int j = 0; j < A.size(); ++j) {
            if (count[A[j]] == 0) K--;
            count[A[j]]++;
            while (K < 0) {
                count[A[i]]--;
                if (count[A[i]] == 0) K++;
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
