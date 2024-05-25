class Solution {
public:
    vector<string>solve(string s, vector<string>& wordDict, unordered_map<string, vector<string>>&dp)
    {
        if(s == "")
            return {""};
        
        if(dp.find(s) != dp.end())
            return dp[s];
        vector<string> sub;
        vector<string> who;
        for(string word : wordDict)
        {
            int l = word.length();
            string got = s.substr(0,l);
            
            if(got != word)
                continue;
            
            else
                sub = solve(s.substr(l), wordDict, dp);
            
            for(string substring : sub)
            {
                string sp = substring.length() == 0 ? "" : " ";
                who.push_back(word+sp+substring);
            }
                
                
        }
        
        return dp[s] = who;
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string, vector<string>>dp;
        return solve(s, wordDict, dp);
    }
};