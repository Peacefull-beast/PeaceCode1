class Solution {
public:
    int trap(vector<int>& height) 
    {
        int lmax = 0;
        int rmax = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l < r)
        {
            if(height[l] > lmax)
                lmax = max(lmax, height[l]);
            if(height[r] > rmax)
                rmax = max(rmax, height[r]);
            if(lmax < rmax)
            {
                ans+=lmax-height[l];
                l++;
            }
            else
            {
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
            
    }
};