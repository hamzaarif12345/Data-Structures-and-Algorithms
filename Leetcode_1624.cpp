/*
1624. Largest Substring Between Two Equal Characters
Solved
Easy
Topics
Companies
Hint
Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
Example 2:

Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
Example 3:

Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> m;

        for (int i = 0; i < s.size(); i++) {
            m[s[i]].push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = max(ans, abs(m[s[i]][0] - m[s[i]][m[s[i]].size() - 1]));
        }

        return ans - 1; // Subtract 1 to get the distance, not the count of characters.
    }
};
