class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if(source == target)
            return 0;
        unordered_map<int, vector<int>>graph; //
        
        for(int r=0; r < routes.size(); r++)
        {
            for(auto stop : routes[r])
                graph[stop].push_back(r);
        }
        
        queue<int>q;
        vector<bool>vis(routes.size(), false);
        for(auto r : graph[source])
        {
            q.push(r);
            vis[r] = true;
        }
        
        
        int cnt = 1;
        
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int route = q.front();
                q.pop();
                
                
                for(auto stop : routes[route])
                {
                    if(stop == target)
                        return cnt;
                    
                    for(auto nroute : graph[stop])
                    {
                        if(vis[nroute] == false)
                        {
                            vis[nroute] = true;
                            q.push(nroute);
                        }
                    }
                }
                
                
            }
            cnt++;
            
        }
        
        return -1;
    }
};