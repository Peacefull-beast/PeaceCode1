class Solution {
public:
    void dfs(vector<vector<char>>& arr, int  i, int j, int n, int m, vector<vector<int>>&vis, vector<int> delRow, vector<int> delCol)
    {
        vis[i][j] = 1;
        for(int ind =0; ind<4; ind++)
        {
            int nrow = i + delRow[ind];
            int ncol = j + delCol[ind];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && arr[nrow][ncol] == 'O')
            dfs(arr, nrow, ncol, n, m, vis, delRow, delCol);
        }
    }
    void solve(vector<vector<char>>& arr) 
    {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(arr[0][i] == 'O' && vis[0][i] == 0)
            dfs(arr, 0, i, n, m, vis, delRow, delCol);
            if(arr[n-1][i] == 'O' && vis[n-1][i] == 0)
            dfs(arr, n-1, i, n, m, vis, delRow, delCol);
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i][0] == 'O' && vis[i][0] == 0)
            dfs(arr, i, 0, n, m, vis, delRow, delCol);
            if(arr[i][m-1] == 'O' && vis[i][m-1] == 0)
            dfs(arr, i, m-1, n, m, vis, delRow, delCol);
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(arr[i][j] == 'O' && vis[i][j] == 0)
                    arr[i][j] = 'X';
            }
        }
    }
};