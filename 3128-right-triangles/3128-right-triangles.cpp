class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> row(n,0);
        vector<int> col(m,0);
        
        for(int i=0; i<n; i++)
        {
            int ct = 0;
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                    ct++;
            }
            row[i] = ct;
        }
        
        for(int j=0; j<m; j++)
        {
            int ct = 0;
            for(int i=0; i<n; i++)
            {
                if(grid[i][j] == 1)
                    ct++;
            }
            col[j] = ct;
        }
        
        long long  ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] ==1)
                    ans += ((row[i]-1) * (col[j]-1));
            }
        }
        
        return ans;
        
    }
};