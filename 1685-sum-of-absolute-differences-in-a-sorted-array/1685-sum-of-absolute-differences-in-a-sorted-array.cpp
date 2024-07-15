class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> lsum(n, 0);
        vector<int> rsum(n, 0);
        
        for(int i=1; i<n; i++)
            lsum[i] = abs(nums[i] - nums[i-1]);
        
        int psum = 0;
        for(int i=n-1; i>=0; i--)
        {
            lsum[i] = lsum[i]*(n-i);
            psum += lsum[i] ;
            lsum[i] = psum;
                
        }
        
         psum = 0;
        for(int i=n-2; i>=0; i--)
            rsum[i] = abs(nums[i] - nums[i+1]);
        
        
        for(int i=0; i<n; i++)
        {
            rsum[i] = rsum[i]*(i+1);
            psum += rsum[i];
            rsum[i] = psum;
        }
        
        vector<int>ans(n,0);
        ans[0] = lsum[0];
        ans[n-1] = rsum[n-1];
        
        
        for(int i=1;i<n-1; i++)
            ans[i] = lsum[i+1] + rsum[i-1];
        
        
        return ans;
    }
};