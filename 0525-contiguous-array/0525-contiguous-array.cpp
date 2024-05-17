class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int preSum = 0;
        int ans = 0;
        
        unordered_map<int,int>mp;
        mp[0] = -1;
        for (int i = 0; i<nums.size(); i++)
        {
            preSum += nums[i] == 1 ? 1 : -1;
            
            if(mp.find(preSum) != mp.end())
                ans = max(ans, i- mp[preSum]);
            else
                mp[preSum] = i;
        }
        return ans;
    }
};