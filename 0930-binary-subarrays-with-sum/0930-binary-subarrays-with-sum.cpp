class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        vector<int>preSum;
        int sum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int ans = 0;
        for(auto el:nums)
        {
            sum += el;
            
            if(mp.find(sum - goal) != mp.end())
                ans += mp[sum-goal];
            
            mp[sum]++;
        }
        
        return ans;
     }
};