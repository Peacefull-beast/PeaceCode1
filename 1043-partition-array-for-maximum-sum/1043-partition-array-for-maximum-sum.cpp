class Solution {
public:
    int rec(vector<int>& arr, int k, int ind, vector<int>&dp)
    {
        if(ind >= arr.size())
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        int maxi = INT_MIN;
        int ans = 0;
        for(int i = 1; i <= k && ind+i-1 < arr.size(); i++)
        {
            maxi = max(arr[ind+i-1], maxi);
            int temp =  (maxi*i) + rec(arr, k, ind+i, dp);
            ans = max(ans,temp);
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        vector<int>dp(arr.size(), -1);
        return rec(arr, k, 0, dp);
    }
};