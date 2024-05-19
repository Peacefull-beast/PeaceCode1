class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
//         vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
//         int ans = 0;
//         for(int i = 1; i<=n; i++)
//         {
//             for(int j = 1; j<=m; j++)
//             {
//                 if(matrix[i-1][j-1] == '1')
//                 {
//                      dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
//                      ans = max(ans, dp[i][j]);
//                 }   
                
//             }
//         }
//         return ans*ans;
        
        vector<int>prevdp(m+1, 0);
        vector<int>dp(m+1, 0);
        int ans = 0;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                     dp[j] = min(prevdp[j], min(dp[j-1], prevdp[j-1])) + 1;
                     ans = max(ans, dp[j]);
                }
                else
                    dp[j] = 0;
                
            }
            prevdp = dp;
        }
        return ans*ans;
    }
    
};