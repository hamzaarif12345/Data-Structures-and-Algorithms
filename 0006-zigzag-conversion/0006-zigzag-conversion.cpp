class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        int a = s.size();
        vector<vector<char>> mat(numRows, vector<char>(a, '\0')); // initialize with '\0'

        string ans = "";
        int arr[2]; // to store current position
        int c = 0;  // final column used
        int j = 0;  // index for string

        for (int i = 0; j < s.size(); i += numRows - 1) {
            // Vertical down
            for (int k = 0; k < numRows && j < s.size(); k++) {
                mat[k][i] = s[j++];
                arr[0] = k;
                arr[1] = i;
                c = max(c, i);
            }

            // Diagonal up
            for (int l = 0; l < numRows - 2 && j < s.size(); l++) {
                int x = arr[0] - 1;
                int y = arr[1] + 1;
                mat[x][y] = s[j++];
                arr[0] = x;
                arr[1] = y;
                c = max(c, y);
            }
        }

        // Read matrix row-wise
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= c; j++) {
                if (isalpha(mat[i][j]) || mat[i][j] == ',' || mat[i][j] == '.') // filter valid chars
                    ans += mat[i][j];
            }
        }

        return ans;
    }
};
