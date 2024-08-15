class Solution {
public:
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>mp;
        vector<int> deg(n,0);
        for(auto p : prerequisites)
        {
            mp[p[1]].push_back(p[0]);
            deg[p[0]]++;
        }
        
        
        queue<int>q;
        for(int i=0 ;i<n; i++)
            if(deg[i] == 0)
                q.push(i);
        
        vector<int>ans;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto n:mp[u])
            {
                deg[n]--;
                if(deg[n] == 0)
                    q.push(n);
            }
        }
        
        return ans.size() == n ? ans : vector<int>{};
        
        
        
    
        
        
    }
};