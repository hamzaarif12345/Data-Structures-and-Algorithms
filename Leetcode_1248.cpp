/*
1248. Count Number of Nice Subarrays
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int a = 0;
        int ans = 0;
        int n = nums.size();
        
        while (j < n) {
            if (nums[j] % 2 != 0) {
                a++;
            }

            while (a > k) {
                if (nums[i] % 2 != 0) {
                    a--;
                }
                i++;
            }

            if (a == k) {
                int temp = i;
                while (temp < j && nums[temp] % 2 == 0) {
                    temp++;
                }
                ans += (temp - i + 1);
            }
            
            j++;
        }
        
        return ans;
    }
};



/*
Certainly! Let's dive into that specific part of the code:

```cpp
if (a == k) {
    int temp = i;
    while (temp < j && nums[temp] % 2 == 0) {
        temp++;
    }
    ans += (temp - i + 1);
}
```

### Explanation of This Part:

#### Condition Check
```cpp
if (a == k) {
```
- This checks if the current number of odd numbers (`a`) in the subarray from `i` to `j` is exactly `k`.
- If it is, then we have a valid subarray that needs to be considered.

#### Finding the Start of Subarrays
```cpp
int temp = i;
```
- `temp` is initialized to `i` to start checking for potential valid subarrays starting from index `i`.

#### Extending to the Right
```cpp
while (temp < j && nums[temp] % 2 == 0) {
    temp++;
}
```
- This `while` loop increments `temp` until it either reaches `j` or encounters an odd number.
- The goal is to find all subarrays starting from `i` up to just before the next odd number. All these subarrays are valid because they still contain exactly `k` odd numbers.

#### Counting Valid Subarrays
```cpp
ans += (temp - i + 1);
```
- `temp - i + 1` calculates the number of valid subarrays starting from each position between `i` and `temp`.
- These subarrays are counted and added to `ans`.
- For example, if `i` to `temp` covers three indices (`i`, `i+1`, and `i+2`), this means there are three subarrays (`[i..j]`, `[i+1..j]`, `[i+2..j]`) that contain exactly `k` odd numbers.

### Why This Works:
- When `a == k`, you already have a subarray that contains exactly `k` odd numbers.
- Moving `i` to `temp` covers all possible subarrays starting from `i` up to `temp` without introducing another odd number (since you are skipping over even numbers).
- This efficiently counts all subarrays that end at `j` and start from `i` to `temp` with exactly `k` odd numbers.

### Example Walkthrough:
Consider an example with `nums = [1, 1, 2, 1, 1]` and `k = 3`:
- When `i = 0` and `j = 4`, `a == 3`:
    - `temp` starts at `0`, and increments up to `2` because `nums[2] = 2` (an even number).
    - `temp` moves to `2` (end of even numbers).
    - This means subarrays `[0..4]`, `[1..4]`, and `[2..4]` are valid, which are 3 subarrays.

By this approach, the loop counts all valid subarrays with exactly `k` odd numbers efficiently.
*/