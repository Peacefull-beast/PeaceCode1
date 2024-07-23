class Solution {
public:
    void dfs(int u, vector<int>& vis, unordered_map<int, vector<int>>&adj, stack<int>&st, bool &cycle)
    {
        vis[u] = 1;
        for(auto n : adj[u])
        {
            if(vis[n] == 0)
            dfs(n, vis, adj, st, cycle);
            else if(vis[n] == 1)
            {
                cycle = true;
                return;
            }
        }
        vis[u] = 2;
        st.push(u);
    }
    
    
    vector<int>topo(vector<vector<int>>&edges, int n)
    {
        unordered_map<int, vector<int>>adj;
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
        }
        
        
        stack<int>st;
        vector<int>vis(n+1, 0);
        bool cycle = false;
        vector<int> order;
        for(int i=1; i<=n ;i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, vis, adj, st, cycle);
                if(cycle == true)
                    return {};
            }
        }
        
        while(!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }
        
        
        return order;
    }
    
    
    
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        vector<int> row = topo(rowConditions, k);
        vector<int> col = topo(colConditions, k);
        
        vector<vector<int>>ans(k, vector<int>(k, 0));
        
        if(row.empty() == true || col.empty() == true)
            return {};
        
        
        
        
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
            
            {
                if(row[i] == col[j])
                    ans[i][j] = row[i];
            }
        }
        
        return ans;
            
    }
};