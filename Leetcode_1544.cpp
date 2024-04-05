/*1544. Make The String Great
Solved
Easy
Topics
Companies
Hint
Given a string s of lower and upper case English letters.

A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

0 <= i <= s.length - 2
s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

Notice that an empty string is also good.

 

Example 1:

Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
Example 2:

Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
Example 3:*/
#include <stack>
#include <string>

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char> t;
        t.push(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (!t.empty() && abs(t.top() - s[i]) == 32) {  // Check if characters are equal ignoring case
                t.pop();  // Remove both characters if they annihilate
            } else {
                t.push(s[i]);  // Otherwise, push the current character
            }
        }

        // Reconstruct the string from the stack
        while (!t.empty()) {
            ans += t.top();
            t.pop();
        }

        reverse(ans.begin(), ans.end());  // Reverse the string to get the correct order
        return ans;
    }
};
