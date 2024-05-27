#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if (row >= grid.size() || col >= grid[0].size())
            return INT_MAX;

        if (row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = solve(row + 1, col, grid, dp);
        int right = solve(row, col + 1, grid, dp);

        return dp[row][col] = grid[row][col] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};
