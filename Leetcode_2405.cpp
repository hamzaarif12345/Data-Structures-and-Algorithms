/*
2405. Optimal Partition of String
Solved
Medium
Topics
Companies
Hint
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

 

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.*/
class Solution {
public:
    int partitionString(string s) {
        int idx = 0;
        int count = 0;
        unordered_map<char, bool> mp; // unordered_map to keep track of characters in current substring
        while (idx < s.length()) {
            if (mp.find(s[idx]) != mp.end()) { // if current character has already appeared in current substring
                count++; // increment count
                mp.clear(); // clear unordered_map to start a new substring
            }
            mp[s[idx]] = true; // mark current character as seen
            idx++; // move to next character
        }
        return count + 1; // return number of substrings (add 1 because we need to count the last substring as well)
    }
};
