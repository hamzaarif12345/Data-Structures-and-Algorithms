/*1903. Largest Odd Number in String
Solved
Easy
Topics
Companies
Hint
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.*/

#include <string>
using namespace std;

class Solution {
public:
    bool e(char a) {
        return !(a == '2' || a == '4' || a == '0' || a == '6' || a == '8');
    }

    string largestOddNumber(string num) {
        int a = num.size() - 1;
        string ans = "";
        
        if (e(num[a])) {
            return num;
        } else {
            while (a >= 0 && !e(num[a])) {
                a--;
            }
            
            if (a >= 0) {
                ans = num.substr(0, a + 1);
            }
        }
        
        return ans;
    }
};
