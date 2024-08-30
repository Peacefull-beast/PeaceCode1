class Solution {
public:
    int n;
    int m;
    vector<vector<int>>ans;
    vector<int>nr = {-1, 0, 1, 0};
    vector<int>nc = {0, -1, 0 ,1};
    int dfs(int r, int c, vector<vector<int>>& matrix)
    {
        if(ans[r][c] != 0)
            return ans[r][c];
        int maxl = 1;
        for(int i=0; i<4; i++)
        {
            int nrow = r + nr[i];
            int ncol = c + nc[i];

            bool cond = (nrow >= 0) && (ncol >= 0) && (nrow < n) && (ncol < m);

            if(cond)
            {
                if(matrix[nrow][ncol] > matrix[r][c])
                {
                    int temp = dfs(nrow, ncol, matrix);
                    maxl = max(maxl,1 + temp);
                }
            }   
        }
        return ans[r][c] = maxl;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        n = matrix.size();
        m = matrix[0].size();

        ans = vector<vector<int>>(n, vector<int>(m,0));

        int mp = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            mp = max(mp, dfs(i,j, matrix));
        }

        return mp;
    }
};