class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p=0,n=0;
        for(auto a : nums){
            if(a < 0) n++;
            if(a > 0) p++;
        }
        return max(p,n);
    }
};