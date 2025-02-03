class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int ans=0;
        if(!nums.size()) return 0;
        if(nums.size()==1) return 1;
        for(int k=1;k<nums.size();k++){
            if(nums[k] > nums[j]) j++;
            else {i=k; j=k;}
            ans=max(ans,j-i+1);
        }
        reverse(nums.begin(),nums.end());
        i=j=0;
        for(int k=1;k<nums.size();k++){
            if(nums[k] > nums[j]) j++;
            else {i=k; j=k;}
            ans=max(ans,j-i+1);
        }return ans;
    }
};