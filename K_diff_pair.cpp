/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;
        int ans=0;
        for(auto x:a)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(a.find(x.first+k)!=a.end())
                ans++;
        }
        
        return ans;
    }
};

//  My code refinded by GPT
int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int i = 0, j = 1;  // Start with two pointers at different positions.

    while (i < nums.size() && j < nums.size()) {
        if (i != j && nums[j] - nums[i] == k) {
            count++;
            i++;  // Move i to avoid duplicates.
            j++;  // Move j to find more pairs.
            // Skip all elements equal to nums[i] and nums[j].
            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
            while (j < nums.size() && nums[j] == nums[j - 1]) j++;
        } else if (nums[j] - nums[i] > k) {
            i++;  // Try to decrease the difference.
            if (i == j) j++;  // Ensure i and j are different.
        } else {
            j++;  // Try to increase the difference.
        }
    }
    cout<<count;
    return count;
}