class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0;
        int res = 0;
        int j =0;
        
        while(j < nums.size())
        {
            mp[nums[j]]++;
            while(mp.size() > k && i <= j)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            
            
            res = res + (j-i+1);
            j++;
        }
        
        
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans  = atMostKDistinct(nums, k) - atMostKDistinct(nums, k-1);
        return ans;
    }
};