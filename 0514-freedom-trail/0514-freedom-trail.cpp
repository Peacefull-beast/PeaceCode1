class Solution {
public:
    int getMin(string &key, string &ring, int rInd, int kInd, unordered_map<char, vector<int>>&mp, vector<vector<int>>&dp)
    {
        if(kInd == key.length())
            return 0;
        int minans = INT_MAX;
        vector<int>pos = mp[key[kInd]];
        if(dp[kInd][rInd] != -1)
            return dp[kInd][rInd];
        for(auto &po : pos)
        {
            int cw = abs(rInd- po);
            int acw = ring.length()-cw;
            int minStep = min(cw, acw);
            int curAns = minStep + getMin(key, ring, po, kInd+1, mp, dp);
            minans = min(minans, curAns);
                
        }
        return dp[kInd][rInd] = 1+minans;
            
    }
    int findRotateSteps(string ring, string key) 
    {
        unordered_map<char, vector<int>>mp;
        for(int i = 0 ;i < ring.length(); i++)
        {
            char ch = ring[i];
            mp[ch].push_back(i);
        }
        vector<vector<int>>dp(key.length(), vector<int>(ring.length(), -1));
        return getMin(key, ring, 0, 0, mp, dp);
        
    }
};