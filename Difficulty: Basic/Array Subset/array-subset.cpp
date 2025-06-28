class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,pair<int,int>> m;
        for(auto e: a) m[e].first++;
        for(auto e: b) m[e].second++;
        for(auto e: b){
            if(m[e].first < m[e].second) return false;
        }
        return true;
    }
};