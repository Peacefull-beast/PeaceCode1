class Solution {
public:
    int n;
    long long helper(vector<int>& a, vector<int>& b,int i,  int k, vector<vector<long long>>&dp)
    {
        if(i == n)
            return 0;
        
        
        if(dp[i][k] != -1)
            return dp[i][k];
        long long take = 0, nottake = 0;
        if(k == 1)
        {
            take = a[i] + helper(a,b,i+1,k, dp);
            nottake = helper(a,b,i+1,2, dp);
        }
        else if(k == 2)
        {
            take = b[i] + helper(a,b,i+1,k, dp);
            nottake = helper(a,b,i+1,1, dp);
        }
        
        
        return dp[i][k] = max(take, nottake);
        
        
    }
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) 
    {
        n = a.size();
        vector<vector<long long>>dp(n, vector<long long>(3, -1));
        return max(helper(a, b, 0, 1, dp), helper(a,b, 0, 2, dp));
        
    }
};