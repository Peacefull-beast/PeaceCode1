class Solution {
public:
    void dfs(vector<vector<int>> &arr, vector<vector<int>>&vis, int i, int j, int n, int m, vector<int> delRow, vector<int> delCol)
    {
        vis[i][j] = 1;

        for(int ind =0; ind<4; ind++)
        {
            int nrow = i + delRow[ind];
            int ncol = j + delCol[ind];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               arr[nrow][ncol] == 1 &&
               vis[nrow][ncol] == 0)
               dfs(arr, vis, nrow, ncol, n, m, delRow, delCol);
        }
    }
    int numEnclaves(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        int  m =arr[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};

        for(int i=0;i<m;i++)
            {
                if(arr[0][i] == 1 && vis[0][i] == 0)
                dfs(arr, vis, 0, i, n, m, delRow, delCol);
                if(arr[n-1][i] == 1 && vis[n-1][i] == 0)
                dfs(arr, vis, n-1, i, n, m, delRow, delCol);
            }
            for(int i=1;i<n;i++)
            {
                if(arr[i][0] == 1 && vis[i][0] == 0)
                dfs(arr, vis, i, 0, n, m, delRow, delCol);
                if(arr[i][m-1] == 1 && vis[i][m-1] == 0)
                dfs(arr, vis, i, m-1, n, m, delRow, delCol);
            }
            int ans = 0;
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<m; j++)
                {
                    if(arr[i][j] == 1 && vis[i][j] == 0)
                    ans++;   
                }
            }
            return ans;
    }
};