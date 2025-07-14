class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        ans.push_back(arr[0]);
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= ans.back()[1]) {
                // Merge current interval with the last interval in ans
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            } else {
                // No overlap, add new interval
                ans.push_back(arr[i]);
            }
        }
        return ans;
        // 1 3  
    }
};