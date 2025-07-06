class FindSumPairs {
public:
    vector<int> n,m;
    unordered_map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n=nums1;
        m=nums2;
        for(auto a: m) mp[a]++;
    }
    
    void add(int index, int val) {
        int b=m[index];
        mp[b]--;
        mp[b+val]++;
        m[index]=b+val;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto a: n){
            if(mp.find(tot-a)!=mp.end()) ans+=mp[tot-a];
        }return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */