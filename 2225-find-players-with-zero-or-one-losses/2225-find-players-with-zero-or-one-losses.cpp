class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        vector<vector<int>>ans(2);
        unordered_map<int, pair<int, int>>mp; //player->win ,loss
        for(auto match : matches)
        {
            mp[match[0]].first++;
            mp[match[1]].second++;
        }
        
        for(auto pl : mp)
        {
            if(pl.second.second == 0)
                ans[0].push_back(pl.first);
            if(pl.second.second == 1)
                ans[1].push_back(pl.first);
        }
        
        // Sort the results
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};