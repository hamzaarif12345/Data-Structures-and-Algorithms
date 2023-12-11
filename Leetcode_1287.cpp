/*
1287. Element Appearing More Than 25% In Sorted Array
Solved
Easy
Topics
Companies
Hint
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    int findSpecialInteger(std::vector<int>& arr) {
        std::unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        int a = m.begin()->first; // Initialize a with the first element in the map
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second > m[a]) {
                a = it->first;
            }
        }

        return a;
    }
};


// a more better solution

    public int findSpecialInteger(int[] arr) {
        int n = arr.length, t = n / 4;

        for (int i = 0; i < n - t; i++) {
            if (arr[i] == arr[i + t]) {
                return arr[i];
            }
        }
        return -1;
    }