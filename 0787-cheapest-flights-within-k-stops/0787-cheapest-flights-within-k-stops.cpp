class Solution {
public:
    int solve(unordered_map<int,vector<pair<int,int>>>&mp, int src, int dest, int k, vector<vector<int>>& dp)
    {
        if( k < 0)
            return INT_MAX;
        
        if(k >= 0 && src == dest)
            return 0;
        
        if(dp[src][k] != -1)
            return dp[src][k];
        
        int price = INT_MAX;
        for(auto ne:mp[src])
        {
            int next = ne.first;
            int cost = ne.second;
            int cost_new = solve(mp, next, dest, k-1, dp);
            if(cost_new != INT_MAX)
                price = min(price, cost+cost_new);      
        }
        return dp[src][k] = price;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        unordered_map<int,vector<pair<int,int>>>mp; //src -> {dest, price}
        
        for(auto fl : flights)
            mp[fl[0]].push_back({fl[1], fl[2]});
        
        vector<vector<int>>dp(n, vector<int>((k+2), -1));
        
        int ans = solve(mp, src, dst, k+1, dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};