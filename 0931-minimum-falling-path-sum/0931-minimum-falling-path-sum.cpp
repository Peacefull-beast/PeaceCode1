class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        // Base case: 
        for (int i = 0; i < m; ++i) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        // Dynamic Programming: Iterate from the second bottom row upwards
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) 
            {
                dp[i][j] = matrix[i][j] + dp[i + 1][j]; //down
                if (j > 0) 
                {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j - 1]); // Move down and left
                }
                if (j < m - 1) 
                {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j + 1]); // Move down and right
                }
            }
        }

        // Find the minimum falling path sum in the top row of dp
        int minSum = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};
