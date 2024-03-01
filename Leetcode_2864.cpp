/*

Code
Testcase
Testcase
Test Result
2864. Maximum Odd Binary Number
Solved
Easy
Topics
Companies
Hint
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

 

Example 1:

Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
Example 2:

Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
 
*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c1=0,c0=0;
        for(auto a: s){
            if(a=='1') c1++;
            else c0++;
        }
        string ans="";
        for(int i=0;i<c1-1;i++){
            ans+='1';
        }
        for(int i=0;i<c0;i++) ans+='0';
        return ans+'1';
    }
};