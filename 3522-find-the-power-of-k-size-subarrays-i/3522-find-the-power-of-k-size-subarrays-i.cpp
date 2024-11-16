class Solution {
public:
    int isSorted(const vector<int>& nums, int start, int k) {
        for (int i = start + 1; i < start + k; i++) {
            if (nums[i] - nums[i - 1]!=1) {
                return -1; // Not sorted
            }
        }
        return nums[start + k - 1]; // Return last element if sorted
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; i++) { // Include last valid start index
            ans.push_back(isSorted(nums, i, k));
        }
        return ans;
    }
};
