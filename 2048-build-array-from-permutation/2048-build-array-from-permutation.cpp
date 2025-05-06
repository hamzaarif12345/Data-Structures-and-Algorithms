class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int j;
        for(int i=0;i<nums.size();i++){
            j=nums[i];
            ans.push_back(nums[j]);
        }return ans;
    }
};