#define mod 1000000007

class Solution {
public:
    int solve(int n, int ac, int lc , vector<vector<vector<int>>>& dp) {

        if (ac >= 2)
            return 0; 
        if (lc >= 3)
            return 0; 
        
        if (n == 0)
            return 1; 
        if (dp[n][ac][lc] != -1)
            return dp[n][ac][lc]; 
        
        int present = solve(n-1, ac, 0, dp);
        int absent = solve(n-1, ac+1, 0, dp);
        int late = solve(n-1, ac, lc+1, dp);
        
        int c = 0;
        c = (c+present)%mod;
        c = (c+absent)%mod;
        c = (c+late)%mod;
        
        return dp[n][ac][lc] = c;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, dp); 
    }
};




