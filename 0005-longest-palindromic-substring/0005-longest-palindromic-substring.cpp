class Solution {
public:
    bool solve(string &s, int l, int r, vector<vector<int>>&dp)
    {
        if(l >= r)
            return 1;
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        if(s[l] == s[r])
            return dp[l][r] = solve(s, l+1, r-1, dp);
        
        return dp[l][r] = false;
    }
    string longestPalindrome(string s) 
    {
        int n = s.length();
        
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        int max_l = INT_MIN;
        int s_ind = 0;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if(solve(s, i, j, dp) && j-i+1 > max_l)
                {
                    s_ind = i;
                    max_l = j-i+1;
                }
            }
        }
        
        return s.substr(s_ind, max_l);
    }
};