#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<unordered_map<ll, int>> dp(n);  //dp[ind][diff]
        int ans= 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0; j<i; j++)
            {
                ll diff = (ll) nums[i] - nums[j];
                
                dp[i][diff] += dp[j][diff] +1;
                ans+=dp[j][diff];
            }
        }
        
        return ans;
    }
};