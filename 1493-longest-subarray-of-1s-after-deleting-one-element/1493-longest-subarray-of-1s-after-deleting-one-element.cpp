class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int ans = 0;
        int i = 0;
        int j = 0;
        int temp = 0;
        
        while(j < nums.size())
        {
            if(nums[j] == 0)
                temp++;
            
            while(temp > 1 && i < j)
            {
                if(nums[i] == 0)
                    temp--;
                i++;
            }
            
            ans = max(ans, (j-i));
            j++;
        }
        
        return ans;
        
    }
};