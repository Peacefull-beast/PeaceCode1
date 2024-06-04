class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind >= nums.size() - 1) {
            return 0;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int max_d = nums[ind];
        int ans = INT_MAX;
        for (int i = 1; i <= max_d && ind + i < nums.size(); i++) {
            int temp = solve(nums, ind + i, dp);
            if (temp != INT_MAX) {
                ans = min(ans, 1 + temp);
            }
        }
        
        return dp[ind] = ans;
    }
    
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
