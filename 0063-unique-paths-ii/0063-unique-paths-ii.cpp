class Solution {
public:
            int solve(int row, int col, vector<vector<int>> &dp, int m , int n, vector<vector<int>>& grid) {
        if (row >= m || col >= n || grid[row][col] == 1)
            return 0;

        if (row == m - 1 && col == n - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = solve(row + 1, col, dp, m, n, grid);
        int right = solve(row, col + 1, dp, m, n, grid);

        return dp[row][col] = (down + right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, dp, m, n, grid);
    }
};