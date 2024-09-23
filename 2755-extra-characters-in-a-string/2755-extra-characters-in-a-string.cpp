class Solution {
public:
    int solve(string &s, vector<string>& dict, int ind, vector<int>& dp) {
        if (ind >= s.length())
            return 0;
        
        if (dp[ind] != -1) 
            return dp[ind];
        
        int minExtra = s.length(); 
        
        
        for (auto &str : dict) 
        {
            int len = str.size();
            string word = s.substr(ind, len);
            if (ind + len <= s.length() && word == str) 
                minExtra = min(minExtra, solve(s, dict, ind + len, dp));
            
        }
        
        
        minExtra = min(minExtra, 1 + solve(s, dict, ind + 1, dp));
        
        dp[ind] = minExtra;
        return dp[ind];
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1); 
        return solve(s, dictionary, 0, dp);
    }
};
