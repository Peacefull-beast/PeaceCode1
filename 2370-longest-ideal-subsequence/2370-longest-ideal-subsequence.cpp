class Solution {
public:
    int answer(string &s, int k, int ind, char prev, vector<vector<int>>&dp)
    {
        if(ind == s.length())
            return 0;
        
        
        // Special case handling for ' '
        int prevIndex = (prev == ' ') ? 26 : prev - 'a';
        if(dp[ind][prevIndex] != -1)
            return dp[ind][prevIndex];
        int pick = 0;
        if(abs(s[ind] - prev) <= k || prev == ' ')
            pick = 1 + answer(s, k, ind+1, s[ind], dp);
        int npck = answer(s, k, ind+1, prev, dp);
        
        return dp[ind][prevIndex] = max(pick, npck);
            
        
        
    }
    
    int longestIdealString(string s, int k) 
    {
        int n = s.length();
        char ch = ' ';
        
        vector<vector<int>>dp(n, vector<int>(27,-1));
        int ans = answer(s,k,0, ch, dp);
        return ans;   
    }
};