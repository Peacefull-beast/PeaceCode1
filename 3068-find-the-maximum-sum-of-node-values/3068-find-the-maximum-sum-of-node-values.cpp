class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        long long ans = 0;
        long long cnt = 0;
        long long minval = INT_MAX;
        for(int i = 0; i<nums.size(); i++)
        {
            long long num = nums[i];
            if((num^k) > num)
            {
                ans += num^k;
                minval = min(minval, (long long)(num^k)-num);
                cnt++;
            }
            else
            {
                ans += num;
                minval = min(minval, (long long)(num)- (num^k));   
            }  
        }
        if(cnt%2 == 0)
        return ans;
        else
            return ans - minval;
    }
};