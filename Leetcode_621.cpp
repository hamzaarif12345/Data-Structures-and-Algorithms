/*
621. Task Scheduler
Solved
Medium
Topics
Companies
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m; // this is the more of math solution
        int count =0;
        for(auto a: tasks){
            m[a]++;
            count=max(count,m[a]);
        }
        int ans=(count-1)*(n+1);
        for(auto a: m){
            if(a.second==count) ans++;
        }return max((int)tasks.size(),ans);

    }
};