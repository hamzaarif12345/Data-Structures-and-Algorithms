/*
343. Integer Break
Medium
3.9K
371
Companies
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.



The first thing we should consider is : What is the max product if we break a number N into two factors?

I use a function to express this product: f=x(N-x)

When x=N/2, we get the maximum of this function.

However, factors should be integers. Thus the maximum is (N/2)*(N/2) when N is even or (N-1)/2 *(N+1)/2 when N is odd.

When the maximum of f is larger than N, we should do the break.

(N/2)*(N/2)>=N, then N>=4

(N-1)/2 *(N+1)/2>=N, then N>=5

These two expressions mean that factors should be less than 4, otherwise we can do the break and get a better product. The factors in last result should be 1, 2 or 3. Obviously, 1 should be abandoned. Thus, the factors of the perfect product should be 2 or 3.

The reason why we should use 3 as many as possible is

For 6, 3 * 3>2 * 2 * 2. Thus, the optimal product should contain no more than three 2.

Below is my accepted, O(N) solution.
*/
public class Solution {
    public int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product = 1;
        while(n>4){
            product*=3;
            n-=3;
        }
        product*=n;
        
        return product;
    }
}