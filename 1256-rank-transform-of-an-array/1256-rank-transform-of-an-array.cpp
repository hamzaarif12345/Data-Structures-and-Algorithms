class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans,temp;
        unordered_map<int,int> m;
        for(auto a: arr) {
            if(m[a]==0) {m[a]=1;temp.push_back(a);}
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            m[temp[i]]=i+1;
        }
        for(auto a: arr){
            ans.push_back(m[a]);
        }
        return ans;
    }
};