/*
1143. Longest Common Subsequence
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Initialize the 2D array
        int ans[1001][1001] = {0};

        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j])
                    ans[i + 1][j + 1] = ans[i][j] + 1;
                else
                    ans[i + 1][j + 1] = max(ans[i][j + 1], ans[i + 1][j]);
            }
        }

        return ans[text1.size()][text2.size()];
    }
};
