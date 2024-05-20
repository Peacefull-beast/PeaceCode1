class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,vector<int>>mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]].push_back(i);
        int ind = INT_MAX;
        for(auto el:mp)
        {
            if(el.second.size() == 1)
                ind = min(ind,el.second[0]);
        }
        if(ind == INT_MAX)
        return -1;
        else
            return ind;
    }
};