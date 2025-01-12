class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int ans=0;
        priority_queue<int> pq;
        for(auto a: nums) pq.push(a);
        int a=pq.top();
        while (!pq.empty()){
            ans=max(ans, a-pq.top());
            a=pq.top();
            pq.pop();
        }return ans;
    }
};