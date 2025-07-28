class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int vw=0;
        vector<int> v;
        for(int i=0;i<mat.size();i++){
            int s=0;
            for(int j=0;j<mat.size();j++){
                s+=mat[i][j];
            }
            v.push_back(s);
        }
        
        for(int i=0;i<mat.size();i++){
            int s=0;
            for(int j=0;j<mat.size();j++){
                s+=mat[j][i];
            }
            v.push_back(s);
        }
        
        
        int m=*max_element(v.begin(),v.end());
        for(auto a: v) vw+=(m-a);
        return (vw/2);
    }
};