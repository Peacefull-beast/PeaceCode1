class Solution {
public:
    vector<int> nr = {-1, 0, 1}; 
    vector<int> nc = {1, 1, 1};  
    
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
        if (dp[row][col] != -1) 
            return dp[row][col];
        
        int max_moves = 0;
        for (int i = 0; i < 3; i++) {
            int nrow = row + nr[i];
            int ncol = col + nc[i];
            
            bool cond = (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size());
            
            if (cond && grid[nrow][ncol] > grid[row][col]) {
                max_moves = max(max_moves, 1 + solve(grid, nrow, ncol, dp));
            }
        }
        dp[row][col] = max_moves;
        return max_moves;
    }
    
    
    int maxMoves(vector<vector<int>>& grid) {
        int max_moves = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        
        for (int row = 0; row < n; row++) {
            max_moves = max(max_moves, solve(grid, row, 0, dp));
        }
        
        return max_moves;
    }
};
