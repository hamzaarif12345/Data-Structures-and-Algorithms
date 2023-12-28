/*345. Reverse Vowels of a String
Solved
Easy
Topics
Companies
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:*/

class Solution {
public:
    bool isV(char c) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'U' || c == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        string result = s;
        string vowels;

        for (auto i : s) {
            if (isV(i)) {
                vowels += i;
            }
        }

        reverse(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isV(s[i])) {
                result[i] = vowels[j++];
            }
        }

        return result;
    }
};
