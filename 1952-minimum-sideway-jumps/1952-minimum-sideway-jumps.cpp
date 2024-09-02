class Solution {
public:
    int n;
    
    int solve(vector<int>& obstacles, int ind, int lane, vector<vector<int>>& dp) {
       
        if (ind == n - 1)
            return 0;

        
        if (dp[ind][lane] != -1)
            return dp[ind][lane];

        
        if (obstacles[ind] == lane)
            return dp[ind][lane] = n + 1;

        
        int minJumps = INT_MAX;

        for (int i = 1; i <= 3; ++i) {
            if (i != lane && obstacles[ind] != i) 
                minJumps = min(minJumps, 1 + solve(obstacles, ind + 1, i, dp));

            else 
                minJumps = min(minJumps, solve(obstacles, ind + 1, lane, dp));
        }

        return dp[ind][lane] = minJumps;
    }
    
    int minSideJumps(vector<int>& obstacles) {
        n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(4, -1)); 

        return solve(obstacles, 0, 2, dp);
    }
};
