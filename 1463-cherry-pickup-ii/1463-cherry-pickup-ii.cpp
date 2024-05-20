class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col1, int col2, vector<vector<vector<int>>>&dp)
    {
        if(col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size())
            return 0;
        
        if(row == grid.size())
            return 0;
        
        int res = 0;
        res+=grid[row][col1];
        
        if(col2 != col1)
            res+=grid[row][col2];
        
        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        
        int maxans = 0;
        for(int x = col1-1; x <= col1+1; x++)
        {
            for(int y = col2-1; y <= col2+1; y++)
                maxans = max(maxans, solve(grid, row+1, x, y, dp));
        }
        //cout<<"1..";
        return dp[row][col1][col2] = res+maxans;

    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();;
        int m = grid[0].size();
        
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1,-1)));
        return solve(grid, 0, 0, m-1,dp);
    }
};