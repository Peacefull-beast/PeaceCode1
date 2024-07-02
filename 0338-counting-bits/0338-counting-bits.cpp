class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int>ans(n,0);
        ans.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if(i%2 == 0)
                ans[i] = ans[i/2];
            else
                ans[i] = ans[i/2]+1;
        }
        
        
        return ans;
    }
};