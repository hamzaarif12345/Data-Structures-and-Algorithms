class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, right = 0, res = 0;
        
        while (right < s.length()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                res = max(res, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }
        
        return res;
    }
};
