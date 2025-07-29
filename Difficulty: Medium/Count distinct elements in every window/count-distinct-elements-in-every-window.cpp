class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> m;
        vector<int> ans;

        // Count frequency in first window
        for (int i = 0; i < k; i++) {
            m[arr[i]]++;
        }
        ans.push_back(m.size());

        // Slide the window
        for (int i = 1; i <= arr.size() - k; i++) {
            // Remove frequency of outgoing element
            m[arr[i - 1]]--;
            if (m[arr[i - 1]] == 0) {
                m.erase(arr[i - 1]);
            }

            // Add frequency of incoming element
            m[arr[i + k - 1]]++;

            ans.push_back(m.size());
        }

        return ans;
    }
};