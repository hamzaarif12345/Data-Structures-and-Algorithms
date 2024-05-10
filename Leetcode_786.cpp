/*786. K-th Smallest Prime Fraction
Solved
Medium
Topics
Companies
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

 

Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]*/


#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        multimap<double, pair<int, int>> m;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                double f = (double)arr[i] / arr[j];
                m.insert({f, {arr[i], arr[j]}});
            }
        }

        int count = 0;
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); ++it) {
            count++;
            if (count == k) {
                result.push_back(it->second.first);
                result.push_back(it->second.second);
                break;
            }
        }
        return result;
    }
};
