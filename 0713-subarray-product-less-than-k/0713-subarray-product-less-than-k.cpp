class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        vector<int>pre;
        int pro = 1;
        
        int i = 0; 
        int j = 0;
        int ans = 0;
        while(j < nums.size())
        {
            pro*=nums[j];
            while(pro >= k && i<=j)
            {
                pro/=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        
        return ans;
        
        
    }
};