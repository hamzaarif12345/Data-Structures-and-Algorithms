class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> m;
        for(auto a: nums1) m[a[0]]=a[1];
        for(auto a: nums2){
            if(m.find(a[0]) != m.end()) m[a[0]]+=a[1];
            else m[a[0]]=a[1];
        }
        vector<vector<int>> ans;
        for(auto a : m) ans.push_back({a.first,a.second});
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};