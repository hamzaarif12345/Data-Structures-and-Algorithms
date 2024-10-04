class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        int sum = 0;
        unordered_map<int, int> m;
        for (int a : skill) {
            m[a]++;
            sum += a;
        }
        int n = skill.size();
        if (sum % (n / 2) != 0) return -1;
        int t = sum / (n / 2);
        for (int a : skill) {
            if (m[a] == 0) continue;
            int complement = t - a;
            if (m[complement] > 0) {
                ans += a * 1LL * complement;
                m[a]--;
                m[complement]--;
            } else {
                return -1;
            }
        }
        return ans;
    }
};
