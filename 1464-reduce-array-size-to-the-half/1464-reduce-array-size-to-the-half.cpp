class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int o = arr.size();
        int s=o;
        int ans=0;
        unordered_map<int,int> m;
        for(auto a: arr) m[a]++;
        priority_queue<int> pq;
        for(auto a : m) pq.push(a.second);
        while(s > int (o/2)){
            s-=pq.top();
            //pq.pop();
            ans++;
            pq.pop();
        }return ans;
        

    }
};