/*
1653. Minimum Deletions to Make String Balanced
Solved
Medium
Topics
Companies
Hint
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.

 

Example 1:

Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
Example 2:

Input: s = "bbaaaaabb"
Output: 2
Explanation: The only solution is to delete the first two characters.
 
*/
class Solution {
public:
    int minimumDeletions(string s) {
    int n=s.length();
    stack<char> stk;
    int c=0;
    for(int i=0;i<n;i++)
    {
        if (!stk.empty() && stk.top()=='b' && s[i]=='a')
            stk.pop(),c++;
        else stk.push(s[i]);
    }
    return c;
}   
};



