class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>row(n,0);
        vector<int>col(m,0);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1)
                {
                    row[i]+=1;
                    col[j]+=1;
                }
        
        vector<vector<int>>ans(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int r1 = row[i];
                int c1 = col[j];
                int r0 = n-r1;
                int c0 = m-c1;
                ans[i][j] = r1+c1-r0-c0;
            }
        }
        
        return ans;
    }
};