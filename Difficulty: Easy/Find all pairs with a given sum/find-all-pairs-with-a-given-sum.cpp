class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int target, vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end()); // for sorted output by 'a'
    unordered_map<int, int> m2;
    for (int b : arr2) m2[b]++;
    
    vector<pair<int, int>> ans;
    for (int a : arr1) {
        int b = target - a;
        if (m2.find(b) != m2.end() && m2[b] > 0) {
            for (int i = 0; i < m2[b]; ++i) {
                ans.push_back({a, b});
            }
        }
    }
    return ans;
}

};