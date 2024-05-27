class Solution {
public:
        int solve(int row, int col, vector<vector<int>> &dp, int m , int n) {
        if (row >= m || col >= n)
            return 0;

        if (row == m - 1 && col == n - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = solve(row + 1, col, dp, m, n);
        int right = solve(row, col + 1, dp, m, n);

        return dp[row][col] = (down + right);
    }

    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, dp, m, n);
    }
};