class Solution {
public:
    vector<int>cost;
    vector<int>time;

    int bfs(int src, int dest, int maxTime, unordered_map<int,vector<vector<int>>>& mp) 
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[src], time[src], src});
        
        
        
        while(!pq.empty())
        {
            vector<int>v = pq.top(); 
            pq.pop();
            
            int c = v[0];
            int t = v[1];
            int node = v[2];
            
            for(auto nbr : mp[node])
            {
                int nnode = nbr[0];
                int tt = nbr[1];
                int cc = nbr[2];
                
                
                if(t + tt <= maxTime)
                {
                    if (cost[nnode] > c + cc) 
                    {
                        cost[nnode] = c + cc;
                        time[nnode] = t + tt;
                        pq.push({cost[nnode], time[nnode], nnode});
                    }


                    else if (time[nnode] > t + tt) 
                    {
                        time[nnode] = t + tt;
                        pq.push({c + cc, time[nnode], nnode});
                    }
                }
            }
        }
        
        return cost[dest] == INT_MAX ? -1:cost[dest];
        
        
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        unordered_map<int, vector<vector<int>>> mp;  // {node, {neighbor node, time to travel, cost}}

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];
            

            mp[u].push_back({v, t, fees[v]});
            mp[v].push_back({u, t, fees[u]});
        }
        int n = fees.size();
        
        
        cost.resize(n, INT_MAX);
        time.resize(n, INT_MAX);
        cost[0] = fees[0];
        time[0] = 0;

        return bfs(0, n-1, maxTime, mp);
    }
};
