class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&mp, vector<int>&vis, int node)
    {
        vector<int>nei = mp[node];
        vis[node] = 1;
        
        for(auto n : nei)
        {
            if(vis[n] == 0)
                dfs(mp, vis, n);
        }
        return;
    }
    
    
    
    int makeConnected(int n, vector<vector<int>>& con) 
    {
        if(con.size() < n-1)
            return -1;
        
        unordered_map<int, vector<int>>mp;
        for(auto c : con)
        {
            int u = c[0];
            int v = c[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<int>vis(n,0);
        int ans = 0;
        
        
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                dfs(mp, vis, i);
            }
        }
        
        return ans-1;
    }
};