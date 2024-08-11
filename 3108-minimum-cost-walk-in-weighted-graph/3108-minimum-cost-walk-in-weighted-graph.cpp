class Solution {
public:
    vector<int> parent;
    int find(int x)
    {
        if(parent[x] == x)
            return x;
        
       return parent[x] = find(parent[x]);    
    }
    
    void Union(int x, int y)
    {
        parent[y] = x;
    }
    
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        parent.resize(n);
        vector<int>cost(n, -1);
        
        for(int i=0 ;i<n; i++)
            parent[i] = i;
        
        
        
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            int p_u = find(u);
            int p_v = find(v);
            
            if(p_u != p_v)
            {
                Union(p_u, p_v);
                cost[p_u] &= cost[p_v];
            }
            
            cost[p_u] &= w;
            
            
        }
        
        vector<int>res;
        
        for(auto q:query)
        {
            int s = q[0];
            int d = q[1];
            if(s == d)
                res.push_back(0);
            
            
            int ps = find(s);
            int pd = find(d);
            if(ps != pd)
                 res.push_back(-1);
            else
                res.push_back(cost[ps]);
        }
        
        return res;
    }
};