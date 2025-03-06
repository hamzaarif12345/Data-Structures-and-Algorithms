class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, bool> m;
        int n = grid.size();
        int repeated, missing;
        
        // Initialize the map with all numbers from 1 to n*n
        for (int i = 1; i <= n * n; i++) {
            m[i] = false;
        }

        // Detect the repeated number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                if (m[val]) {
                    repeated = val;
                }
                m[val] = true;
            }
        }

        // Detect the missing number
        for (auto& p : m) {
            if (!p.second) {
                missing = p.first;
                break;
            }
        }

        return {repeated, missing};
    }
};
