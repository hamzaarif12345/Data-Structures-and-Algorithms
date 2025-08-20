class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(int i=0;i<mat.size();i++){
            int m=mat[0].size();
            if(mat[i][0] < mat[i][m-1]){
                if(mat[i][0] <= x and x <= mat[i][m-1]){
                    for(int j=0;j<m;j++){
                        if(mat[i][j] ==x) return true;
                    }
                    return false;
                }
            } 
            else {
                for(int j=0;j<mat[0].size();j++){
                    if(mat[i][j] == x) return true;
                }
            }
           
        }
         return false;
    }
};
