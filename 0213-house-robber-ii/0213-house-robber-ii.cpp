class Solution {
public:
    int answer(int n,int k, vector<int>& nums, vector<int>& dp)
    {
    if(n < k)
    return 0;
    if(dp[n] != -1)
    return dp[n];
    int inc = answer(n-2, k,nums, dp) + nums[n];
    int ninc = answer(n-1, k,nums, dp);
    return dp[n] = max(inc, ninc);
    }
    
    int rob(vector<int>& nums) {
         int n = nums.size() - 1;
    if(n==0)
    return nums[0];
    vector<int> dpf(n + 1, -1);
    vector<int> dpl(n + 1, -1);
    return max(answer(n, 1, nums, dpf),
                answer(n-1, 0, nums, dpl));
        
    }
};