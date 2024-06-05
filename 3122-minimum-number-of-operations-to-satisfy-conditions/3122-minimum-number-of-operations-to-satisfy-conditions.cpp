class Solution {
public:
    int solve(int j, int keep, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (j == m) {
            return 0; 
        }
        
        if (dp[j][keep] != -1) {
            return dp[j][keep];
        }
        
        int cost = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] != keep) {
                cost++;
            }
        }
        
        int minAns = INT_MAX;
        for (int k = 0; k <= 9; k++) {
            if (k == keep) continue;
            minAns = min(minAns, cost + solve(j + 1, k, grid, dp));
        }
        
        return dp[j][keep] = minAns;
    }
    
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(10, -1));
        
        int minAns = INT_MAX;
        for (int keep = 0; keep <= 9; keep++) {
            minAns = min(minAns, solve(0, keep, grid, dp));
        }
        
        return minAns;
    }
};
