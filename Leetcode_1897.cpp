/*
1897. Redistribute Characters to Make All Strings Equal
Solved
Easy
Topics
Companies
Hint
You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.

 

Example 1:

Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.
Example 2:

Input: words = ["ab","a"]
Output: false
Explanation: It is impossible to make all the strings equal using the operation.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int a = words.size();
        unordered_map<char, int> m;

        for (const auto& word : words) {
            for (char c : word) {
                m[c]++;
            }
        }

        for (auto i : m) {
            if ((i.second) % a == 0) continue;
            return false;
        }

        return true;
    }
};
