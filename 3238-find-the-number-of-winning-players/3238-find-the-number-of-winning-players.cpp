class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) 
    {
        vector<vector<int>>mp(n, vector<int>(11,0));
        
        for(auto pi:pick)
        {
            int p = pi[0];
            int c = pi[1];
            
            mp[p][c]++;
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<11; j++)
                if(mp[i][j] > i)
                {
                    ans++;
                    break;
                }
        }
        
        return ans;
        
        
    }
};