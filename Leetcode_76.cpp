/*
76. Minimum Window Substring
Solved
Hard
Topics
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::string ans;
        int minLen = INT_MAX;

        if (s.size() < t.size() || s.empty() || t.empty()) return ans;

        std::unordered_map<char, int> mt;

        for (auto a : t) mt[a]++;

        int requiredChars = mt.size();
        int formedChars = 0;
        int start = 0, end = 0;
        int minStart = 0;

        while (end < s.size()) {
            if (mt.find(s[end]) != mt.end()) {
                mt[s[end]]--;

                if (mt[s[end]] == 0) {
                    formedChars++;
                }
            }

            while (formedChars == requiredChars) {
                int currentLen = end - start + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minStart = start;
                }

                if (mt.find(s[start]) != mt.end()) {
                    mt[s[start]]++;

                    if (mt[s[start]] > 0) formedChars--;
                }

                start++;
            }

            end++;
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
