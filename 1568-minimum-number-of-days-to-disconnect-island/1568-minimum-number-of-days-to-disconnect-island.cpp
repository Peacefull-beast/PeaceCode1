class Solution {
public:
    int n;
    int m;
    vector<int>nr = {-1, 0, 1, 0};
    vector<int>nc = {0, -1, 0 ,1};
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        vis[i][j] = 1;
        
        for(int t = 0; t < 4; t++) {
            int nrow = i + nr[t];
            int ncol = j + nc[t];
            
            bool cond = (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m);
            if(cond && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                dfs(grid, vis, nrow, ncol);
            }
        }
    }
    
    int count(vector<vector<int>>& grid, vector<vector<int>> vis) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    dfs(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int nisland = count(grid, vis);
        
        if(nisland == 0) return 0;
        if(nisland >= 2) return 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    vis.assign(n, vector<int>(m, 0));  
                    int temp = count(grid, vis);
                    if(temp >= 2 || temp == 0) return 1;
                    
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};
