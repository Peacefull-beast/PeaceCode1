class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind == nums.size() - 1) {
            return true;
        }
         
        if (ind >= nums.size()) {
            return false;
        }
        
        if (dp[ind] != -1) {
            return dp[ind];
        }
        
        int max_d = nums[ind];
        bool ans = false;
        for (int i = 1; i <= max_d && ind + i < nums.size(); i++) {
            if (solve(nums, ind + i, dp)) {
                ans = true;
                break;
            }
        }
        
        return dp[ind] = ans;
    }
    
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};
