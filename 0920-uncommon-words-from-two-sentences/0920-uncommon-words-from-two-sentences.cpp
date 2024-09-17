class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string temp = "";
        vector<string> ans;
        unordered_map<string, int> m;
        for (int i = 0; i <= s1.size(); i++) {
            if (i < s1.size() && isalnum(s1[i])) {
                temp += s1[i];
            } else {
                if (!temp.empty()) {
                    m[temp]++;
                    temp = "";
                }
            }
        }
        for (int i = 0; i <= s2.size(); i++) {
            if (i < s2.size() && isalnum(s2[i])) {
                temp += s2[i];
            } else {
                if (!temp.empty()) {
                    m[temp]++;
                    temp = "";
                }
            }
        }
        for (auto& a : m) {
            if (a.second == 1) {
                ans.push_back(a.first);
            }
        }

        return ans;
    }
};
