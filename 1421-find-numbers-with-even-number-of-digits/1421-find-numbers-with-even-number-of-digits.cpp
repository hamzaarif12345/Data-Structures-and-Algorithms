class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(to_string(nums[i]).size() % 2 == 0) ans++;
        }return ans;
    }
};