class Solution {
public:
    vector<int>nr = {0, 1, 0 ,-1};
    vector<int>nc = {-1, 0, 1, 0};
    void dfs(vector<vector<int>>&matrix, vector<vector<int>>&vis, int i, int j)
    {
        vis[i][j] = 1;
        for(int t=0; t<4; t++)
        {
            int nrow = i + nr[t];
            int ncol = j + nc[t];
            bool cond = (nrow>=0 && ncol>=0 && nrow<matrix.size() && ncol<matrix.size());
            if(cond && vis[nrow][ncol] == 0 && matrix[nrow][ncol] == 0)
                dfs(matrix, vis, nrow, ncol);
            
            
        }   
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        
        int sz = n*3;
        
        vector<vector<int>>matrix(sz, vector<int>(sz,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n; j++)
            {
                if(grid[i][j] == '/')
                {
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\')
                {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }
        int ans = 0;
        vector<vector<int>>vis(sz, vector<int>(sz,0));
        for(int i=0; i<sz; i++)
        {
            for(int j=0; j<sz; j++)
            {
                if(vis[i][j] == 0 && matrix[i][j] == 0)
                {
                    dfs(matrix, vis, i , j);
                    ans++;
                }
                
            }
        }
        
        return ans;
        
    }
};