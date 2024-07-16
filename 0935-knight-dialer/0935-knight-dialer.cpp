class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    
    int knightDialer(int n) {
        if (n == 1) return 10;
        
        // dp[i][j] represents the number of distinct numbers of length i ending with digit j
        vector<vector<long long>> dp(n, vector<long long>(10, 0));
        
        
        for (int i = 0; i < 10; ++i) {
            dp[0][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int move : jumps[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][move]) % MOD;
                }
            }
        }
        
        long long result = 0;
        for (int i = 0; i < 10; ++i) {
            result = (result + dp[n - 1][i]) % MOD;
        }
        
        return result;
    }
};
