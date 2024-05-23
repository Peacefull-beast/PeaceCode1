class Solution {
public:
    int solve(long long n, unordered_map<long long, int>& dp) {
        if (n == 1) return 0;
        
        if (dp.find(n) != dp.end()) return dp[n];
        
        if ((n & 1) == 0) {
            dp[n] = 1 + solve(n / 2, dp);
        } else {
            dp[n] = 1 + min(solve(n + 1, dp), solve(n - 1, dp));
        }
        
        return dp[n];
    }

    int integerReplacement(int n) {
        unordered_map<long long, int> dp;
        return solve(n, dp);
    }
};