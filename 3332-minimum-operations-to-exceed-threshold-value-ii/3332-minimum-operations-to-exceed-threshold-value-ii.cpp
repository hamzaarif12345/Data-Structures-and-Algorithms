class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long , vector<long long>, greater<long long>> pq;
        int ans=0;
        for(auto a: nums) pq.push(a);
        while(pq.top() < k && pq.size()>=2){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            long long ad=(min(a,b)*2)+max(a,b);
            pq.push(ad);
            ans++;
        }
        return ans;
    }
};