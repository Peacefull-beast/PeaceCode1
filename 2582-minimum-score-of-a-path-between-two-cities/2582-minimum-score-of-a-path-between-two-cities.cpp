#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
       
        unordered_map<int, vector<pair<int, int>>> mp;
        
        
        vector<int> dist(n, INT_MAX);
        dist[0] = INT_MAX;  

        
        for(auto r : roads)
        {
            int u = r[0] - 1; 
            int v = r[1] - 1;
            int wt = r[2];

            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({INT_MAX, 0}); 
        while(!pq.empty())
        {
            int d = pq.top().first;  
            int node = pq.top().second;  
            pq.pop();

            for(auto nbr : mp[node])
            {
                int next_node = nbr.first;
                int edge_weight = nbr.second;

                int new_score = min(d, edge_weight);

                if(new_score < dist[next_node])
                {
                    dist[next_node] = new_score;
                    pq.push({new_score, next_node});
                }
            }
        }

        
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};
