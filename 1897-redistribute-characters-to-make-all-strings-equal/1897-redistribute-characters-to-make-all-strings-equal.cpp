class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        unordered_map<char,int>mp;
        for(auto word : words)
        {
            for(auto c : word)
                mp[c]++;
        }
        
        for(auto p : mp)
        {
            if(p.second%(words.size()) != 0)
                return false;
        }
        
        return true;
    }
};