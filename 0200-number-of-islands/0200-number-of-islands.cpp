class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>&vis,vector<int>&nr, 
             vector<int>&nc, int row, int col, int n, int m)
    {
        for(int i = 0; i<4; i++)
        {
            int nrow = row+nr[i];
            int ncol = col+nc[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
               grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
            {
                vis[nrow][ncol] = 1;
                bfs(grid, vis, nr, nc, nrow, ncol, n , m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ans = 0;
        vector<int>nr = {0, 1, 0, -1};
        vector<int>nc = {1, 0, -1, 0};
        for(int i = 0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    bfs(grid, vis, nr, nc, i, j, n, m);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};