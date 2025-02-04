class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty()) return 0;  // Handle empty input

        int ans = nums[0], sum = nums[0];  // Initialize sum with first element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];  // Continue the ascending sum
            } else {
                ans = max(ans, sum);  // Store the maximum sum
                sum = nums[i];  // Start a new ascending sequence
            }
        }
        return max(ans, sum);  // Compare the last sequence sum
    }
};
