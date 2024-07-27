class Solution {
public:
    long long fuel = 0;
    long long dfs(int node, int par, unordered_map<int, vector<int>>&mp, int seats)
    {
        int ppl = 1;
        for(auto child : mp[node])
        {
            if(child != par)
                ppl += dfs(child, node, mp, seats);
        }
        if(node != 0)
            fuel += ceil((double)ppl/seats);
        return ppl;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        unordered_map<int, vector<int>>mp;
        for(auto r : roads)
        {
            int u = r[0];
            int v = r[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        
        dfs(0, -1, mp, seats);
        return fuel;
    }
};