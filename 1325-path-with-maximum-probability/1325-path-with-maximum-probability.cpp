#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end_node) {
        
        priority_queue<pair<double, int>> pq;

        
        vector<double> dist(n, 0.0);

        
        unordered_map<int, vector<pair<int, double>>> mp;

        // Construct the graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            
            mp[u].push_back({v, prob});
            mp[v].push_back({u, prob});
        }

        
        dist[start] = 1.0;
        pq.push({1.0, start});

        
        while (!pq.empty()) {
            int u = pq.top().second;
            double p = pq.top().first;
            pq.pop();

            if (u == end_node) {
                return p;
            }

            for (auto vec : mp[u]) {
                int adjNode = vec.first;
                double prob = vec.second;

               
                if (dist[adjNode] < p * prob) {
                    dist[adjNode] = p * prob;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        
        return 0.0;
    }
};
