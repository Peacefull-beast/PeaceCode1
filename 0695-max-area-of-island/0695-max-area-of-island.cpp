#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col) 
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        int ans = 0;
        
        while (!q.empty()) 
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            ans++;
            
            for (int i = 0; i < 4; i++) 
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && 
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) 
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; // Mark as visited when pushing to queue
                }
            }
        }
        
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); // 0 -> not visited; 1 -> visited
        int ans = 0;
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] == 1 && vis[i][j] == 0) 
                {
                    int area = bfs(grid, vis, i, j);
                    ans = max(ans, area);
                }
            }
        }
        
        return ans;
    }
};
