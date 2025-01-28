class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        multimap<int, vector<int>> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a: points){
            int d=((a[0])* (a[0]) +  (a[1])*(a[1]));
            //m[d].push_back(a[0]);
            //m[d].push_back(a[1]);
            m.insert({d,{a[0],a[1]}});
            pq.push(d);
        }
        for (auto it = m.begin(); k > 0 && it != m.end(); ++it, --k) {
            ans.push_back(it->second); // Add the closest point
        }

        return ans;
        
    }
};