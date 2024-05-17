class Solution {
public:
    int answer(vector<int>&nums, int ind, int prev, vector<vector<int>>&dp)
    {
        if(ind >= nums.size())
            return 0;
        if(dp[ind][prev+1] != -1)
            return dp[ind][prev+1];
        int inc = 0;
        if(prev==-1 || nums[prev] < nums[ind])
            inc = 1 + answer(nums, ind+1, ind,dp);
        int exc = answer(nums, ind+1, prev,dp);
        return dp[ind][prev+1]=max(inc,exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return answer(nums, 0, -1, dp);
        
    }
};