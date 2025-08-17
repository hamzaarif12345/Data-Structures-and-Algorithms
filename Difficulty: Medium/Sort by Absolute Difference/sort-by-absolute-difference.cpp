class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
    vector<vector<int>> v;
    
    for (int i = 0; i < arr.size(); i++) {
        int a = abs(arr[i] - x);
        v.push_back({a, arr[i]});
    }
    
    // Stable sort ensures tie-breaking keeps original order
    stable_sort(v.begin(), v.end(), [](const vector<int>& p1, const vector<int>& p2) {
        return p1[0] < p2[0];
    });
    
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = v[i][1];
    }
}


};