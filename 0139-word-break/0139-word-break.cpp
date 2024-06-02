class Solution {
public:
    bool solve(string s, vector<string>& dict, unordered_map<string, bool>& memo) {
        if (s == "")
            return true;
        
        if (memo.find(s) != memo.end())
            return memo[s];
        
        for (auto word : dict) {
            int l = word.length();
            if (s.substr(0, l) == word) {
                if (solve(s.substr(l), dict, memo)) {
                    return memo[s] = true;
                }
            }
        }
        
        return memo[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;
        return solve(s, wordDict, memo);
    }
};
