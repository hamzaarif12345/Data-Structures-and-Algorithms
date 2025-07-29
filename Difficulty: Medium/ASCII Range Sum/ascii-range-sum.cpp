class Solution {
  public:
    vector<int> asciirange(string& s) {
        vector<int> ans;
        unordered_map<char, pair<int, int>> m;

        // Initialize with -1 to distinguish unset values
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = {i, -1}; // first occurrence
            } else {
                m[s[i]].second = i; // update last occurrence
            }
        }

        for (auto a : m) {
            int start = a.second.first;
            int end = a.second.second;

            if (start != -1 && end != -1 && end > start + 1) {
                int t = 0;
                for (int i = start + 1; i < end; i++) {
                    t += (int)s[i]; // ASCII sum between first and last occurrence
                }
                ans.push_back(t);
            } 
        }

        return ans;
    }
};