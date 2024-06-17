class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int step, int n) {
        if (step == n * n - 1) {
            return true;
        }
        
        vector<int> nr = {-1, -1, -2, -2, +1, +1, +2, +2};
        vector<int> nc = {+2, -2, +1, -1, +2, -2, +1, -1};
        
        vis[row][col] = 1;
        
        for (int i = 0; i < 8; i++) {
            int nrow = row + nr[i];
            int ncol = col + nc[i];
            
            bool isValid = nrow >= 0 && ncol >= 0 && nrow < n && ncol < n;
            if (isValid && !vis[nrow][ncol] && grid[nrow][ncol] == step + 1) {
                if (dfs(nrow, ncol, grid, vis, step + 1, n)) {
                    return true;
                }
            }
        }
        
        vis[row][col] = 0;
        return false;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int step = 0;
        
        if (grid[0][0] != 0) {
            return false; 
        }
        
        return dfs(0, 0, grid, vis, step, n);
    }
};
