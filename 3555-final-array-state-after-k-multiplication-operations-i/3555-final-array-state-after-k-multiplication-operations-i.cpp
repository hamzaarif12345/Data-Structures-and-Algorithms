class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i=0;
        for(auto a: nums) {pq.push({a,i}); i++;}
        while(k){
            auto a=pq.top();
            pq.pop();
            a.first*=multiplier;
            pq.push({a.first,a.second});
            k--;
        }
        int n=nums.size();
        vector<int> ans(n,0);
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            ans[a.second]=a.first;
        }return ans;
    }
};