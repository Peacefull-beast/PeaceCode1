class Solution {
public:
    int fn(vector<vector<int>>& grid, int n, int row, int col,vector<vector<int>>&dp)
    {
         if(row == n-1)
                return grid[row][col];
         if(dp[row][col] != -1)
             return dp[row][col];
         int ans = INT_MAX;
         for(int cur = 0; cur < n ;cur++)
         {
             if(cur != col)
             {
                 int temp = fn(grid, n, row+1, cur, dp);
                 ans = min(temp,ans);
             }      
         }
        return dp[row][col] = grid[row][col]+ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int ans = INT_MAX;
        
        vector<vector<int>>dp(n,vector<int>(n, -1));
        for(int i = 0; i < n; i++ )
        {
            int temp = fn(grid, n, 0, i, dp);
            ans = min(temp, ans);
        }
        return ans;
        
        
    }
};