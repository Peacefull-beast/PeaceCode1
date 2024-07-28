#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
public:
    #define P pair<long long, int>
    const int MOD = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<P>> mp;
        
        for (auto& r : roads) {
            int u = r[0];
            int v = r[1];
            long long w = r[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, 0}); // {dist, node}
        dist[0] = 0;
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for (auto& nbr : mp[node]) {
                int adjnode = nbr.first;
                long long wt = nbr.second;
                
                if (dist[adjnode] > d + wt) {
                    dist[adjnode] = d + wt;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                } else if (dist[adjnode] == d + wt) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
