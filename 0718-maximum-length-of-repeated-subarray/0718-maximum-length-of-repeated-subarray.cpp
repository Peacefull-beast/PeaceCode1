class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<vector<int>>tab(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1;j<=m; j++)
                if(nums1[i-1] == nums2[j-1])
                {
                    tab[i][j] = 1 + tab[i-1][j-1];
                    ans = max(ans, tab[i][j]);
                }
        }
        
        return ans;
    }
    
    
};