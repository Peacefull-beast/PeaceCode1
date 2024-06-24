class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int ans = 0 ;
        for(int i = 0; i<nums.size()-2; i++)
        {
            if(nums[i] == 0)
            {
                ans++;
                for(int j=i; j<= i+2; j++)
                    nums[j]^=1;
            }
        }
        int n = nums.size();
        if(nums[n-1] == 0 || nums[n-2] == 0)
            return -1;
        return ans;
    }
};