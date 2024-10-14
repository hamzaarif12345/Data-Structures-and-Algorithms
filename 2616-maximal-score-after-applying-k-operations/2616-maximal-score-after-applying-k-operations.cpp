class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto a : nums) {
            pq.push(a);
        }
        
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            int a = pq.top();
            ans += a;
            pq.pop();
            pq.push(ceil(a / 3.0));  
        }
        
        return ans;
    }
};