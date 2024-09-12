class Solution {
public:
    bool fn(string &word, unordered_map<char,int>&mp)
    {
        for(auto c : word)
        {
            if(mp.find(c) == mp.end())
                return false;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        unordered_map<char,int>mp;
        for(auto c: allowed)
            mp[c]++;

        int ans = 0;
        for(auto word:words)
            ans += (fn(word,mp)) ? 1 : 0;

        return ans;
    }
};