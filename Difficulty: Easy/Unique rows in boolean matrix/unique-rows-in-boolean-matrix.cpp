class Solution {
  public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
    vector<vector<int>> ans;
    unordered_set<string> seen;

    for (int i = 0; i < row; i++) {
        string key = "";
        for (int j = 0; j < col; j++) {
            key += to_string(M[i][j]) + "_";  // build unique key for row
        }

        if (seen.find(key) == seen.end()) {
            seen.insert(key);
            vector<int> v;
            for (int j = 0; j < col; j++) {
                v.push_back(M[i][j]);
            }
            ans.push_back(v);
        }
    }
    return ans;
}

};