class Solution {
public:
    void dfs(vector<vector<int>>& grid, int &mx, int &curr, int i, int j) {
    // Check boundaries and avoid revisiting cells
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) {
        return;
    }

    // Add the current cell's value to curr
    curr += grid[i][j];

    // Update the maximum if the current path value is greater
    mx = max(mx, curr);

    // Mark the cell as visited by setting it to a negative value
    int temp = grid[i][j];
    grid[i][j] = -temp;

    // Explore all four directions
    dfs(grid, mx, curr, i - 1, j); // Up
    dfs(grid, mx, curr, i + 1, j); // Down
    dfs(grid, mx, curr, i, j - 1); // Left
    dfs(grid, mx, curr, i, j + 1); // Right

    // Backtrack: restore the cell's original value
    //grid[i][j] = temp;
    //return mx;
}

    int findMaxFish(vector<vector<int>>& grid) {
        int mx=0;
        //int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int curr=0;
                if(grid[i][j] > 0) {
                    //curr+=grid[i][j];
                    dfs(grid,mx,curr,i,j);
                }
            }
        }
        return mx;
    }
};