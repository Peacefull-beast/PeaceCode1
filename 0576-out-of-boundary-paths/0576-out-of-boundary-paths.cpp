#define mod 1000000007  // Correct the modulo value to 1000000007

class Solution {
public:
    int solve(int row, int col, int remMoves, int n, int m, vector<vector<vector<int>>> &dp) {
        if (row == n || col == m || row < 0 || col < 0)
            return 1;
        if (remMoves == 0)
            return 0;
        
        if (dp[row][col][remMoves] != -1)
            return dp[row][col][remMoves];
        
        int ans1 = solve(row + 1, col, remMoves - 1, n, m, dp);
        int ans2 = solve(row - 1, col, remMoves - 1, n, m, dp);
        int ans3 = solve(row, col + 1, remMoves - 1, n, m, dp);
        int ans4 = solve(row, col - 1, remMoves - 1, n, m, dp);
        
        return dp[row][col][remMoves] = ((ans1 + ans2) % mod + (ans3 + ans4) % mod) % mod;
    }

    int findPaths(int n, int m, int maxMove, int startRow, int startCol) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startCol, maxMove, n, m, dp);
    }
};
