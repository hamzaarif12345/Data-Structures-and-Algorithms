/*
1750. Minimum Length of String After Deleting Similar Ends
Solved
Medium
Topics
Companies
Hint
Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
The prefix and the suffix should not intersect at any index.
The characters from the prefix and suffix must be the same.
Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (possibly zero times).

 

Example 1:

Input: s = "ca"
Output: 2
Explanation: You can't remove any characters, so the string stays as is.
Example 2:
*/
#include <string>
#include <set>

class Solution {
public:
    int minimumLength(std::string s) {
        int i = 0;
        int j = s.size() - 1;

        if (s.size() == 1) {
            return 1;
        }

        while (i < j && s[i] == s[j]) {
            char current = s[i];

            while (i <= j && s[i] == current) {
                i++;
            }

            while (j >= i && s[j] == current) {
                j--;
            }
        }

        return j - i + 1;
    }
};
