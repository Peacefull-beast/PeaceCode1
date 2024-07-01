class Solution {
public:
    int solve(vector<int>& nums, int tar, int ind, vector<vector<int>>&dp)
    {
        if(tar == 0)
            return 1;
        
        if(ind >= nums.size() || tar < 0)
            return 0;
            
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
        
        int pick = solve(nums, tar-nums[ind], 0, dp);
        int npick = solve(nums, tar, ind+1, dp);
        return dp[ind][tar] = (pick+npick);
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));
        return  solve(nums, target, 0, dp);  
    }
};




