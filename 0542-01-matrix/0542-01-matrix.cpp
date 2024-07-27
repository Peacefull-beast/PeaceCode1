class Solution {
public:
    void solve(vector<vector<int>> &mat, vector<vector<int>>&vis, vector<vector<int>>&ans,                queue<pair<pair<int,int>,int>>&q, vector<int> delRow,  vector<int> delCol, int n, int m)
    {
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int step = q.front().second;

            q.pop();

            ans[x][y] = step;

            for(int i = 0;i<4;i++)
            {
                int nrow = x + delRow[i];
                int ncol = y + delCol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) 
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},step+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue< pair< pair<int,int> ,int> >q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            if(mat[i][j] == 0)
            {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            else
                vis[i][j] = 0;

        }
        solve(mat, vis, ans, q, delRow, delCol, n, m);
        return ans;
    }
};