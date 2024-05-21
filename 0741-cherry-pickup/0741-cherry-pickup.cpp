class Solution {
public:
    
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2, int c2,vector<vector<vector<vector<int>>>>&dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(r1 >= n || r2 >= n || c1 >= m || c2 >= m || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        
        if(dp[r1][c1][r2][c2] != -1)
            return  dp[r1][c1][r2][c2];
        
        int col1 = grid[r1][c1];
        int col2 = grid[r2][c2];
        int cherries = 0;
        if(c1 == c2 && r1 == r2) //came on same block while returning
        {
            cherries += grid[r1][c1];
            if(r1 == n-1 && c1 == m-1) // on last block
                return  dp[r1][c1][r2][c2] = grid[r1][c1];
            
            grid[r1][c1] = 0; //cherries collected
        }
        
        else
        {
            cherries += (grid[r1][c1] + grid[r2][c2]);
            grid[r1][c1] = 0;
            grid[r2][c2] = 0;
        }
        
        int p1 = solve(grid, r1+1, c1, r2+1, c2  ,dp);
        int p2 = solve(grid, r1, c1+1, r2, c2+1  ,dp);
        int p3 = solve(grid, r1+1, c1, r2, c2+1  ,dp);
        int p4 = solve(grid, r1, c1+1, r2+1, c2  ,dp);
        
        grid[r1][c1] = col1;
        grid[r2][c2] = col2;
        
        
        dp[r1][c1][r2][c2] = cherries + max(max(p1,p2), max(p4,p3));
        return dp[r1][c1][r2][c2];
            
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>                   (n+1, vector<int>(n+1, -1))));
        
        int result = solve(grid, 0, 0, 0, 0, dp);
        if(result < 0 || result == -1)
            return 0;
        else
            return result;
        
    }
};