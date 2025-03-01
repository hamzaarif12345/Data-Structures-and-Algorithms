class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) {nums[i]*=2;nums[i+1]=0;}
        }
        vector<int> arr;
        for(auto a: nums) {
            if(a) arr.push_back(a);
        }
        for(int i=0;i<nums.size();i++) {
            if(i < arr.size()) nums[i]=arr[i];
            else nums[i]=0;
        }
        return nums;
    }
};