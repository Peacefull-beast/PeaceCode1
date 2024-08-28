class Solution {
public:
    void dfs(vector<vector<int>>& mat, vector<vector<int>>& vis, int row, int col,  bool &flag, vector<vector<int>>& grid1) {
        
        vis[row][col] = 1;
        
        
        vector<int> nr = {-1, 0, 1, 0};
        vector<int> nc = {0, -1, 0, 1};
        
        
        for (int i = 0; i < 4; i++) 
        {
            int nrow = row + nr[i];
            int ncol = col + nc[i];
            
            
            bool cond = (nrow >= 0) && (nrow < mat.size()) && (ncol >= 0) && (ncol < mat[0].size());
            if (cond && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1) 
            {
                if(grid1[nrow][ncol]==0){
                    // cout<<nrow<<ncol<<" ";
                    flag=true;
                }   
                cout<<nrow<<ncol;
                dfs(mat, vis, nrow, ncol,flag,grid1);
            }
        }
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int n = grid1.size();
        int m = grid1[0].size();
       
        
        vector<vector<int>>vis(n, vector<int>(m,0));
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid2[i][j] == 1 && vis[i][j] == 0 && grid1[i][j] == 1)
                {
                    bool flag = false;
                    dfs(grid2, vis, i, j, flag,grid1);
                    if(flag == false)
                    ans++;

                }
            }
        }
        return ans;
    }
};