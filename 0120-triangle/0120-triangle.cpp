class Solution {
public:
    int solve(int ind, int row, vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
        if(row == triangle.size())
            return 0;
        if(dp[row][ind] != -1)
            return dp[row][ind];
        int down = solve(ind, row+1, triangle,dp);
        int right = solve(ind+1, row+1, triangle, dp);
        
        return dp[row][ind] = triangle[row][ind] + min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        int m = triangle.back().size();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(0, 0, triangle, dp);
    }
};