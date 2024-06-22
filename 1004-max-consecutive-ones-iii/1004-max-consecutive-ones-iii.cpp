class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n0 = 0;
        
        int i = 0;
        int j = 0;
        int len = 0;
        
        int ans = 0;
        while(j < nums.size())
        {
            if(nums[j] == 0)
                n0++;
            while(n0 > k)
            {
                if(nums[i] == 0)
                    n0--;
                len--;
                i++;
            }
            
            
            
            j++;
            len++;
            ans = max(len,ans);
        }
        
        return ans;
    }
};