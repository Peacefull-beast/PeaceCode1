class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        int ans = INT_MAX;
        unordered_map<int,int>mp;
        int n = cards.size();
        for(int i=0; i<n; i++)
        {
            if(mp.find(cards[i]) == mp.end())
            mp[cards[i]] = i;

            else
            {
                int lind = mp[cards[i]];
                int diff = i - lind + 1;
                ans = min(ans, diff);

                mp[cards[i]] = i;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};