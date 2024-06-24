class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        long long int maxf = 0;
        long long int l=0, r=0, t=0, n=nums.size();
        
        while(r < n)
        {
            t+=nums[r];
            while((nums[r]*(r-l+1)) > t+k && l < r)
            {
                t-=nums[l];
                l++;
            }
            maxf = max(maxf, (r-l+1));
            r++;
        }
        
        return maxf;
    }
};