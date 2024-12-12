class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        
        for(auto a: gifts) pq.push(a);
        while(k){
            int b=pq.top();
            pq.pop();
            int c=floor(sqrt(b));
            //ans+=c;
            pq.push(c);
            k--;
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};