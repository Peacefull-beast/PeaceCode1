class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto s:strs)
        {
            string ostr = s;
            sort(s.begin(), s.end());
            mp[s].push_back(ostr);
        }
        for(auto el:mp)
            ans.push_back(el.second);
        return ans;
    }
};