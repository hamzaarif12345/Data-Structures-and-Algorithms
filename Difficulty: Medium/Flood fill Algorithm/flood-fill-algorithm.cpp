//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor) {
    if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
        return;
    if (image[i][j] != color || image[i][j] == newColor)
        return;

    image[i][j] = newColor;

    dfs(image, i + 1, j, color, newColor);
    dfs(image, i - 1, j, color, newColor);
    dfs(image, i, j + 1, color, newColor);
    dfs(image, i, j - 1, color, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int color = image[sr][sc];
    if (color != newColor)
        dfs(image, sr, sc, color, newColor);
    return image;
}

};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends