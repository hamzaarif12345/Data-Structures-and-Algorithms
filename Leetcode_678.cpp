/*
678. Valid Parenthesis String
Solved
Medium
Topics
Companies
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
*/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_paren, star;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left_paren.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {  // s[i] == ')'
                if (!left_paren.empty()) {
                    left_paren.pop();
                } else if (!star.empty()) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*'
        while (!left_paren.empty() && !star.empty()) {
            if (left_paren.top() < star.top()) {
                left_paren.pop();
                star.pop();
            } else {
                break;
            }
        }

        return left_paren.empty();
    }
};
