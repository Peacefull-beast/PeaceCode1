class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>&dp)
    {
        if(ind >= nums.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int pck = nums[ind] + solve(nums, ind+2, dp);
        int npck = solve(nums, ind+1, dp);
        return dp[ind] = max(pck ,npck);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n, -1);
        return solve(nums, 0 , dp);
    }
};