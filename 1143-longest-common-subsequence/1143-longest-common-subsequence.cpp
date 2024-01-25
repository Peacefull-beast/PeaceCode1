class Solution {
public:
    int answer(string &x,string &y ,int m, int n,vector<vector<int>> &dp)
    {
        if(m == 0||n==0)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(x[m-1] == y[n-1])
            return dp[m][n] = 1 + answer(x,y, m-1, n-1, dp);
        return dp[m][n] = 
            max(answer(x,y, m-1,n, dp), answer(x,y,m,n-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
      
        // vector<vector<int>> dp(m, vector<int>(n,-1))
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return answer(text1, text2, m, n,dp);
    }
};