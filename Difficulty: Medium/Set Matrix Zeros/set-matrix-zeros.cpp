class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        set<int> r,c;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) {r.insert(i); c.insert(j);}
            }
        }
        for(auto a: c){
            for(int i=0;i<mat.size();i++) mat[i][a]=0;
        }
        for(auto a: r){
            for(int j=0;j<mat[0].size();j++) mat[a][j]=0;
        }
        
        
    }
};