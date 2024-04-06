/*
1249. Minimum Remove to Make Valid Parentheses
Solved
Medium
Topics
Companies
Hint
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/

#include <string>
#include <stack>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int> indicesToRemove;
        int openCount = 0;

        // First pass: remove invalid closing parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openCount++;
                indicesToRemove.push(i);
            } else if (s[i] == ')') {
                if (openCount > 0) {
                    openCount--;
                    indicesToRemove.pop();
                } else {
                    s[i] = '*'; // Mark invalid closing parentheses for removal
                }
            }
        }

        // Second pass: remove excess opening parentheses
        while (!indicesToRemove.empty()) {
            s[indicesToRemove.top()] = '*'; // Mark invalid opening parentheses for removal
            indicesToRemove.pop();
        }

        // Construct the valid string
        for (char ch : s) {
            if (ch != '*') ans += ch;
        }

        return ans;
    }
};
