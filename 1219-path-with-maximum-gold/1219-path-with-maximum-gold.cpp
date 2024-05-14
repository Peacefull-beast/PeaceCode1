
class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;
        vector<int> nr = {0, 1, 0, -1};
        vector<int> nc = {1, 0, -1, 0};
        int res = grid[row][col]; // Initial result is the gold at the current cell
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + nr[i];
            int ncol = col + nc[i];
            
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] != 0) {
                res = max(res, grid[row][col] + bfs(grid, vis, nrow, ncol));
            }
        }
        vis[row][col] = 0;
        return res;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, bfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};
