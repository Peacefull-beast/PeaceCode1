#define mod 1000000007

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n, int k, int cost) {
        if (row >= m || col >= n)
            return 0;

        if (row == m - 1 && col == n - 1) {
            return (cost + grid[row][col]) % k == 0 ? 1 : 0;
        }

        if (dp[row][col][cost % k] != -1)
            return dp[row][col][cost % k];

        int down = solve(row + 1, col, grid, dp, m, n, k, cost + grid[row][col]);
        int right = solve(row, col + 1, grid, dp, m, n, k, cost + grid[row][col]);

        return dp[row][col][cost % k] = (down + right) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, grid, dp, m, n, k, 0);
    }
};
