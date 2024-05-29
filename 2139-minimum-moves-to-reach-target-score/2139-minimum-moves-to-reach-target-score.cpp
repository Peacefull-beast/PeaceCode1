class Solution {
public:
    int solve(int target, int md,vector<vector<int>>&dp)
    { 
        if(target == 1)
            return 0;
        
        if(dp[target][md] != -1)
            return dp[target][md];

        
        int op1 = solve(target-1, md, dp);
        int op2 = INT_MAX;
        if(target % 2 == 0 &&  md > 0)
            op2 = solve(target/2, md-1, dp);
        
        return dp[target][md] = min(op1, op2) + 1;
        
        
    }
    int minMoves(int target, int md) 
    {
        // vector<vector<int>>dp(target+1, vector<int>(maxDoubles+1, -1));
        // return solve(target, maxDoubles,dp);
        
        int ans = 0;
        while(md != 0 && target != 1)
        {
            if(target % 2 != 0)
            {
                ans++;
                target--;
            }
            target/=2;
            ans++;
            md--;
        }
        
        if(target != 1)
            ans += target-1;
        
        return ans;
    }
};