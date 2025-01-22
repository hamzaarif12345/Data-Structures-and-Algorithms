class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> m;
        unordered_map<int,int> m2,m3;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int a=mat[i][j];
                m[a].first=i;
                m[a].second=j;
            }
        }
        int x=0;
        for(auto a: arr){
            auto b=m[a].first;
            m2[b]++;
            auto c= m[a].second;
            m3[c]++;
            x++;
            if(m2[b]==mat[0].size() || m3[c]==mat.size()) return x-1;
        }
        return x;
    }
};