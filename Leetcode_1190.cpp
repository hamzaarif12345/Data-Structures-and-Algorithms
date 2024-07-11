/*
1190. Reverse Substrings Between Each Pair of Parentheses
Solved
Medium
Topics
Companies
Hint
You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 
*/

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                std::string* temp = new std::string("");
                while (!st.empty() && st.top() != '(') {
                    *temp += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // remove the '(' from the stack
                }
                for (char t_ch : *temp) {
                    st.push(t_ch);
                }
                delete temp; // deallocate memory for temp
            } else {
                st.push(ch);
            }
        }
        
        std::string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans; // build the result string in reverse order
            st.pop();
        }
        return ans;
    }
};