class Solution {
public:
    int ans(vector<int>& nums, vector<int>&dp,int ind)
    {
        // if(ind<0)
        //     return 0;
        // else if(ind==0)
        //     return nums[0];
        // else if(dp[ind]!=-1)
        //     return dp[ind];
        // else
        // {
        //     int np=0+ans(nums,dp,ind-1);
        //     int pick=nums[ind]+ans(nums,dp,ind-2);
        //     return dp[ind]=max(pick,np);
        // }
        int pick,notpick;

        if(ind==nums.size()-1)
            return dp[ind] = nums[ind];

        if(ind>nums.size()-1)
            return 0;

        if(dp[ind]!=-1)
        {
            // cout<<"1...";
            return dp[ind];
        } 
        else
        {
            pick=nums[ind]+ans(nums,dp,ind+2);
            notpick=ans(nums,dp,ind+1);
        }
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int x=nums.size();
        vector<int>dp;
        for(int i=0;i<x;i++)
            dp.push_back(-1);
        return ans(nums,dp,0);
    }
};