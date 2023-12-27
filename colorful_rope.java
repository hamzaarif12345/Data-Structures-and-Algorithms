/*1578. Minimum Time to Make Rope Colorful
Medium
2.9K
86
Companies
Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.

 

Example 1:


Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
Example 3:


Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
 

Constraints:

n == colors.length == neededTime.length
1 <= n <= 105
1 <= neededTime[i] <= 104
colors contains only lowercase English letters.

*/

class Solution {
    public int minCost(String s, int[] cost) {
        int n = s.length();
        int result = 0;
        for (int i=1; i<n; i++) {
            if (s.charAt(i) == s.charAt(i-1)) {
                result = result + Math.min(cost[i], cost[i-1]);
                cost[i] = Math.max(cost[i], cost[i-1]);
            }
        }
        return result;
    }
}

class Solution {
public:
    int minCost(string colors, vector<int>& n) {
        int ans=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){ ans+=min(n[i],n[i-1]);
            n[i]=max(n[i],n[i-1]);}
            
            
        }
        return ans;
    }
};
// see the java code as well


/*
The given code aims to find the minimum cost to make adjacent characters in a string different, based on the provided cost array.

Here's a step-by-step explanation of how the cost calculation works:

1. The function `minCost` takes two parameters: a string `s` and an array `cost` of the same length as the string, where `cost[i]` represents the cost of changing character `s[i]` to a different character.

2. It initializes two variables:
   - `result` to store the total minimum cost, initially set to 0.
   - `n` to store the length of the string `s`.

3. The loop iterates through the string from the 1st index (index 0 is compared with index 1).

4. Inside the loop, it checks if the character at the current index `i` is the same as the character at the previous index `i-1`. If they are the same, this means there is a repetition of characters.

5. To minimize the cost of making these characters different, the code does the following:
   - Adds the minimum cost between `cost[i]` and `cost[i-1]` to the `result`. This represents the cost of changing one of the repeated characters to a different character.
   - Updates `cost[i]` to be the maximum cost between `cost[i]` and `cost[i-1]`. This ensures that the maximum cost is used for the remaining character, as we've already added the minimum cost to the `result`.

6. The loop continues until it has checked all adjacent character pairs in the string.

7. Finally, the function returns the `result`, which represents the minimum cost required to make all adjacent characters different.

The code effectively calculates the minimum cost of transforming the string `s` while avoiding consecutive duplicate characters. It does this by iteratively comparing the cost of making the current character different from the previous one and updating the result accordingly.
*/