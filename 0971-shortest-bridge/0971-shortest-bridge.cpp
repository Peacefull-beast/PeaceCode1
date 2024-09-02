class Solution {
public:
    vector<int> nr = {-1, 0, 1, 0}; 
    vector<int> nc = {0, 1, 0, -1}; 
    int n;
    int m;

   
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int num) {
        vis[row][col] = num; 
        for (int i = 0; i < 4; i++) {
            int nrow = row + nr[i];
            int ncol = col + nc[i];
            bool cond = (nrow >= 0) && (ncol >= 0) && (nrow < n) && (ncol < m);
            if (cond && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                dfs(grid, vis, nrow, ncol, num);
            }
        }
    }

    int solve(queue<pair<int, pair<int, int>>> &q, vector<vector<int>> &vis, vector<vector<int>> visited) 
    {
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int dist = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();

                if (vis[x][y] == 2) 
                    return dist-1;

                for (int i = 0; i < 4; i++) {
                    int nrow = x + nr[i];
                    int ncol = y + nc[i];
                    bool cond = (nrow >= 0) && (ncol >= 0) && (nrow < n) && (ncol < m);
                    if (cond && visited[nrow][ncol] == 0) { 
                        visited[nrow][ncol] = 1; 
                        q.push({dist + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        vector<vector<int>> visited(n, vector<int>(m, 0)); 
        int num = 1;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    dfs(grid, vis, i, j, num);
                    num++;
                }
            }
        }

        
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 1) { 
                    visited[i][j] = 1; 
                    q.push({0, {i, j}});
                }
            }
        }

        int ans = solve(q, vis, visited);
        return ans;
    }
};
