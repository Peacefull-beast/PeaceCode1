class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i = 0; i<nums.size();i++)
            mp[nums[i]]++;
        int max_freq = 0;
        for(auto &i:mp)
        {
            if(i.second > max_freq)
                max_freq = i.second;
        }
        int ans = 0;
        for(auto &i: mp)
        {
            if(i.second == max_freq)
                ans+=max_freq;
        }
        return ans;
    }
};