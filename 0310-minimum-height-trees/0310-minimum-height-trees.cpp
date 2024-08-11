class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>>mp;
        vector<int>deg(n,0);
        
        if(n == 1)
            return {0};
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            
            deg[u]++;
            deg[v]++;
            
            mp[u].push_back(v);
            mp[v].push_back(u);     
        }
        
        vector<int>res;
        
        queue<int>q;
        
        for(int i=0 ;i<n; i++)
            if(deg[i] == 1)
                q.push(i);
        
        while(n > 2)
        {
            int sz = q.size();
            n -= sz;
            while(sz--)
            {
                int u = q.front(); 
                q.pop();
                
                for(int &v : mp[u])
                {
                    deg[v]--;
                    if(deg[v] == 1)
                        q.push(v);
                }
            }
        }
        
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};