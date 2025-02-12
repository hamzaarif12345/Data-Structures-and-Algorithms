class Solution {
public:
    int sd(int num){
        int ans=0;
        string a=to_string(num);
        for(auto b: a){
            ans+=b-'0';
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,priority_queue<int>> m;
        for(auto a : nums){
            int b=sd(a);
            m[b].push(a);
        }
        for(auto a: m){
            if(a.second.size() <=1) continue;
            int temp=a.second.top();
            a.second.pop();
            temp+=a.second.top();
            ans=max(ans,temp);
        }return ans;

    }
};